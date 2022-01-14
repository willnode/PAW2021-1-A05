<?php

// Halaman profil tiap user

require 'include/ceklogin.inc';
include "include/init.inc";
include "include/folunfol.inc";

//query untuk mengambil data user
if (!isset($_GET['id']) && $_SESSION['level'] == 'admin') {
    $query = $dbc->prepare("SELECT * FROM admin WHERE id_admin=:id");
    $query->bindValue(":id", $_SESSION['id']);
    $query->execute();
    $result = $query->fetch(PDO::FETCH_ASSOC);
    include "view/profile_admin.inc";
} else {
    $id = $_GET['id'] ?? $_SESSION['id'];
    $query = $dbc->prepare("SELECT * FROM member WHERE id_member=:id");
    $query->bindValue(":id", $id);
    $query->execute();
    $result = $query->fetch(PDO::FETCH_ASSOC);
    $query = $dbc->prepare("SELECT * FROM connection WHERE id_addmember=:id_add AND id_member=:id");
    $query->bindValue(":id_add", $id);
    $query->bindValue(":id", $_SESSION['id']);
    $query->execute();
    $follow = $query->fetch(PDO::FETCH_ASSOC);
    include "view/profile.inc";
}

