<?php

// Halaman Register

require_once "include/init.inc";
require_once "include/validasi.inc";

// deklarasi valiable validasi
$err =  [];
if (isset($_POST['submit'])) {
    validasiFullName($err, $_POST, "fullname"); //validasi fullname
    validasiUserName($err, $_POST, "username"); //validasi username
    validasiEmail($err, $_POST, "email"); //validasi email
    validasiNoHp($err, $_POST, "nohp"); //validasi nohp
    validasiPass($err, $_POST, "password"); //validasi password
    validasiConfirm($err, $_POST, "confirm", "password"); //validasi confirm password
    required($err, $_POST, "type"); //validasi type member/admin
    // untuk upload foto profile tidak ada didalam register.php
    //cek jika sudah tidak ada error
    if (!$err) {
        // jika tidak ada error, maka masukkan ke database
        if ($_POST['type'] == 'admin')
        $statement = $dbc->prepare("INSERT INTO admin (username_admin, password_admin, fullname_admin, email_admin, nohp_admin, photo_admin) " .
            "VALUES (:username, SHA2(:password, 0), :fullname, :email, :nohp, '')"); //menyiapkan query insert data pada tabel admin
        else
        $statement = $dbc->prepare("INSERT INTO member (username_member, password_member, fullname_member, email_member, nohp_member, photo_member) " .
            "VALUES (:username, SHA2(:password, 0), :fullname, :email, :nohp, '')"); //menyiapkan query insert data pada tabel member

        //menhubungkan data dengan variabel
        $statement->bindValue(':username', $_POST['username']);
        $statement->bindValue(':password', $_POST['password']); // SHA2 encrypt sudah didalam query
        $statement->bindValue(':fullname', $_POST['fullname']);
        $statement->bindValue(":email", $_POST['email']);
        $statement->bindValue(":nohp", $_POST['nohp']);
        $statement->execute(); //menjalankan query
        //akan diarahkan ke halaman login.php
        header("location:login.php");
    }
}

include "view/register.inc"; //menyisipkan file .inc
