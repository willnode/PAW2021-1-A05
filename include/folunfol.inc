<?php


if ($_POST) {
    if ($_POST['action'] == 'follow') {
        $sql = "INSERT INTO connection (id_member, id_addmember) VALUES (:id_member, :id_addmember)";
    } else if ($_POST['action'] == 'unfollow') {
        $sql = "DELETE FROM connection WHERE id_member = :id_member AND id_addmember = :id_addmember";
    } else {
        exit();
    }
    $stmt = $dbc->prepare($sql);
    $stmt->bindParam(':id_member', $_SESSION['id']);
    $stmt->bindParam(':id_addmember', $_POST['id_member']);
    $stmt->execute();
    header("Refresh:0");
    exit();
}