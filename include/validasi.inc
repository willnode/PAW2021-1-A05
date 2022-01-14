<?php

function required(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error[$field_name] = " *" . $field_name . " diperlukan!";
    }
}

function validasiFullName(&$error, $field_list, $field_name)
{
    $pattern = "/^[a-zA-Z '-]+$/"; // format surname (alfabet)
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error[$field_name] = " *" . $field_name . " diperlukan!";
        // cek apakah input hanya terdiri dari huruf
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $error[$field_name] = " *Harus berisi alfabet saja";
    }
}

function validasiUserName(&$error, $field_list, $field_name)
{
    $pattern = "/^[a-zA-Z '-]+$/"; // format surname (alfabet)
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error[$field_name] = " *" . $field_name . " diperlukan!";
        // cek apakah input hanya terdiri dari huruf
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $error[$field_name] = " *Harus berisi alfabet saja";
    } else if (validasiDuplikasi($field_list, $field_name, "admin", "username_admin")) {
        $error[$field_name] = " *Username sudah didaftarkan";
    } else if (validasiDuplikasi($field_list, $field_name, "member", "username_member")) {
        $error[$field_name] = " *Username sudah didaftarkan";
    }
}

function validasiNoHp(&$error, $field_list, $field_name)
{
    $pattern = "/^\+?[\d-]+$/"; // format nomor hp (angka, + diawal dan strip pemisah -)
    // cek apakah field kosong
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $error[$field_name] = " *" . $field_name . " diperlukan!";
        // cek apakah input hanya terdiri dari huruf
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $error[$field_name] = " *Harus berisi format nomor hp yang benar";
    } else if (validasiDuplikasi($field_list, $field_name, "admin", "nohp_admin")) {
        $error[$field_name] = " *Nomor hp sudah didaftarkan";
    } else if (validasiDuplikasi($field_list, $field_name, "member", "nohp_member")) {
        $error[$field_name] = " *Nomor hp sudah didaftarkan";
    }
}

function validasiEmail(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error[$field_name] = " *Email diperlukan!";
        // cek apakah email sesuai format
    } else if (!filter_var($field_list[$field_name], FILTER_VALIDATE_EMAIL)) {
        $error[$field_name] = " *Email tidak valid";
        //cek apakah data yang diisikan belum pernah terdata
    } else if (validasiDuplikasi($field_list, $field_name, "admin", "email_admin")) {
        $error[$field_name] = " *Email sudah didaftarkan";
    } else if (validasiDuplikasi($field_list, $field_name, "member", "email_member")) {
        $error[$field_name] = " *Email sudah didaftarkan";
    }
}

function validasiDuplikasi($field_list, $field_name, $table_name, $field_name_db)
{
    global $dbc;
    $query = $dbc->prepare("SELECT * FROM $table_name WHERE $field_name_db=:$field_name");
    $query->bindValue(":$field_name", $field_list[$field_name]);
    $query->execute();
    // cek apakah data yang diisikan belum pernah terdata
    if ($query->rowCount() > 0) {
        return true;
    } else {
        return false;
    }
}

function validasiPass(&$error, $field_list, $field_name)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name])) {
        $error[$field_name] = " *Password diperlukan";
        // cek apakah panjang password kurang dari 8 karakter
    } else  if (strlen($field_list[$field_name]) < 8) {
        $error[$field_name] = "*Password harus 8 karakter keatas";
        // cek apakah password sudah terdiri dari alpha numeric
    } else if ((preg_match("/^[a-zA-Z]*$/", $field_list[$field_name])) || (preg_match("/^[0-10]*$/", $field_list[$field_name]))) {
        $error[$field_name] = " *Harus ada karakter alfabet dan angka";
    }
}

function validasiConfirm(&$error, $field_list, $field_name1, $field_name2)
{
    // cek apakah field kosong
    if (empty($field_list[$field_name1])) {
        $error[$field_name1] = " *Konfirmasi password diperlukan";
        // cek apakah password sama
    } else if ($field_list[$field_name1] != $field_list[$field_name2]) {
        $error[$field_name1] = " *Password tidak sama!";
    }
}

function validasiPhoto(&$error, $images, $field_name)
{
    $name = $images[$field_name]['name']; //mengambil nama file
    $jenis_gambar = $images[$field_name]['type']; //mengambil ekstensi file
    $ukuran = $images[$field_name]['size']; //mengambil ukuran file
    $lokasi = $images[$field_name]['tmp_name']; //mengambil direktori asal
    //mengecek apakah format sesuai
    if ($jenis_gambar != "image/jpeg" && $jenis_gambar != "image/jpg" && $jenis_gambar != "image/png") {
        $error[$field_name] = " *Format file harus .jpg .jpeg .png";
    } else if ($ukuran > 5000000) {
        //mengecek ukuran apakah melebihi 5mb
        $error[$field_name] = " *Ukuran file terlalu besar";
    } else if (file_exists("../img/" . $name)) {
        //mengecek apakah file sudah ada
        $error[$field_name] = " *File sudah ada";
    } else if (!move_uploaded_file($lokasi, $_SERVER['DOCUMENT_ROOT'] . "/image/profile/" . $name)) {
        //mengecek apakah file berhasil diupload
        $error[$field_name] = " *Gagal upload file";
    } else {
        // OK. simpan hasil upload ke $_POST
        $_POST[$field_name] = $name;
    }
}
