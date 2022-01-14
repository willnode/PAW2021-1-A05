<?php

// Halaman Login

include "include/init.inc";
include "include/validasi.inc";

function cariAdminAtauMember($username, $password) {
    global $dbc; //penggunaan global variabel
    //menyiapkan quert select pada admin
    $query = $dbc->prepare("SELECT * FROM admin WHERE username_admin = :username AND password_admin = SHA2(:password,0)");
    $query->bindValue(":username", $username);
    $query->bindValue(":password", $password);
    $query->execute(); //query dijalankan
    $row = $query->fetch(PDO::FETCH_ASSOC);
    if ($row) {
        return [
            'id' => $row['id_admin'],
            'username' => $row['username_admin'],
            'fullname' => $row['fullname_admin'],
            'email' => $row['email_admin'],
            'photo' => $row['photo_admin'],
            'nohp' => $row['nohp_admin'],
            'level' => 'admin'
        ];
    }
    //menyiapkan quert select pada member
    $query = $dbc->prepare("SELECT * FROM member WHERE username_member = :username AND password_member = SHA2(:password,0)");
    $query->bindValue(":username", $username);
    $query->bindValue(":password", $password);
    $query->execute(); //query dijalankan
    $row = $query->fetch(PDO::FETCH_ASSOC);
    if ($row) {
        return [
            'id' => $row['id_member'],
            'username' => $row['username_member'],
            'fullname' => $row['fullname_member'],
            'email' => $row['email_member'],
            'nohp' => $row['nohp_member'],
            'photo' => $row['photo_member'],
            'level' => 'member'
        ];
    }
    return null;
}
$err = [];
if ($_POST) {
    required($err, $_POST, 'username'); //validasi username
    required($err, $_POST, 'password'); //validasi password
    //cek jika sudah tidak ada error
    if (!$err) {
        //cek data username dan password
        if ($row = cariAdminAtauMember($_POST["username"], $_POST['password'])) {
            session_start(); //memulai session pada server
            // simpan semua data user ke dalam session
            foreach ($row as $key => $value) {
                $_SESSION[$key] = $value;
            }
            header("location:posts.php"); //akan diarahkan ke halaman posts.php
            exit(); //keluar dari halaman ini
        } else {
            $err['match'] = "* Email or password tidak sama";
            //validasi email dan password jika tidak sesuai dengan data pada database
        }
    }
}

include "view/login.inc"; //menyisipkan file login.inc pada folder view
