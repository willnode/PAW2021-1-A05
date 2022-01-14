<?php

// Halaman User Ganti Profil Mereka Sendiri

require 'include/ceklogin.inc';
include "include/init.inc";
include "include/validasi.inc";


// deklarasi valiable validasi
$err =  [];
if (isset($_POST['submit'])) {
    if ($_POST['fullname'] != $_SESSION['fullname'])
        validasiFullName($err, $_POST, "fullname"); //validasi fullname
    if ($_POST['username'] != $_SESSION['username'])
        validasiUserName($err, $_POST, "username"); //validasi username
    if ($_POST['email'] != $_SESSION['email'])
        validasiEmail($err, $_POST, "email"); //validasi email
    if ($_POST['nohp'] != $_SESSION['nohp'])
        validasiNoHp($err, $_POST, "nohp"); //validasi nohp
    if (!empty($_POST['password'])) {
        // handle password baru
        validasiPass($err, $_POST, "password"); //validasi password
        validasiConfirm($err, $_POST, "confirm", "password"); //validasi confirm password
    }
    if (!empty($_FILES['photo']['name'])) {
        validasiPhoto($err, $_FILES, 'photo'); // handle photo baru
    }
    if (!$err) {
        //menyiapkan query insert data pada tabel user
        $statement = $dbc->prepare($_SESSION['level'] == 'member' ?
            "UPDATE member SET
            username_member = :username,
            fullname_member = :fullname,
            email_member = :email,
            nohp_member = :nohp
            WHERE id_member = :id" : "UPDATE admin SET
            username_admin = :username,
            fullname_admin = :fullname,
            email_admin = :email,
            nohp_admin = :nohp
            WHERE id_admin = :id");
        //menhubungkan data dengan variabel
        $statement->bindValue(':id', $_SESSION['id']);
        $statement->bindValue(':username',  $_SESSION['username'] = $_POST['username']);
        $statement->bindValue(':fullname', $_SESSION['fullname'] = $_POST['fullname']);
        $statement->bindValue(":email",  $_SESSION['email'] = $_POST['email']);
        $statement->bindValue(":nohp", $_SESSION['nohp'] = $_POST['nohp']);
        $statement->execute(); //menjalankan query

        if ($_POST['password'] != "") {
            //menyiapkan query insert data pada tabel user
            $statement = $dbc->prepare($_SESSION['level'] == 'member' ?
                "UPDATE member SET
                password_member = SHA2(:password, 0)
                WHERE id_member = :id" : "UPDATE admin SET
                password_admin = SHA2(:password, 0)
                WHERE id_admin = :id");
            //menhubungkan data dengan variabel
            $statement->bindValue(':id', $_SESSION['id']);
            $statement->bindValue(':password', $_POST['password']);
            $statement->execute(); //menjalankan query
        }
        if (!empty($_POST['photo'])) {
            //menyiapkan query insert data pada tabel user
            $statement = $dbc->prepare($_SESSION['level'] == 'member' ?
                "UPDATE member SET
                photo_member = :photo
                WHERE id_member = :id" : "UPDATE admin SET
                photo_admin = :photo
                WHERE id_admin = :id");
            //menhubungkan data dengan variabel
            $statement->bindValue(':id', $_SESSION['id']);
            $statement->bindValue(':photo', $_SESSION['photo'] = $_POST['photo']);
            $statement->execute(); //menjalankan query
        }
        header("location:edit_profile.php");
        exit;
    }
}

include "view/edit_profile.inc"; //include file edit_profile.inc pada volder view
