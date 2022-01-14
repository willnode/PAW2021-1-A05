<?php

// Tambah atau edit pertanyaan/thread dari client

require 'include/ceklogin.inc';
include "include/init.inc";
include "include/validasi.inc";

$err = [];

if ($_SESSION['level'] == 'admin') {
    echo 'Tidak untuk admin';
    exit;
}

if ($_POST) {
    // Thread baru
    required($err, $_POST, 'message');

    if (!$err) {
        // Mode POST, proses..
        $statement = $dbc->prepare("INSERT INTO post (id_member, message) VALUES (:id_member, :message)");
        $statement->bindValue(':id_member', $_SESSION['id']);
        $statement->bindValue(':message', $_POST['message']);
        $statement->execute();
        // balik ke halaman view thread
        header('Location: posts.php');
        exit;
    }
}

include "view/submit.inc";
