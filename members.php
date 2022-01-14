<?php

// Halaman Dashboard setelah login

require 'include/ceklogin.inc';
include "include/init.inc";
include "include/folunfol.inc";

//mengambil seluruh posting (admin) atau yang hanya difollow (member)
if ($_SESSION['level'] == 'admin') {
    $sql = "
    SELECT member.id_member, member.fullname_member from member
    ORDER BY member.id_member DESC";
} else if ($_SESSION['level'] == 'member') {
    $sql = "
    SELECT member.id_member, member.fullname_member, connection.id_addmember from member
    LEFT JOIN (SELECT * FROM connection WHERE id_member = '$_SESSION[id]') connection
    ON connection.id_addmember = member.id_member ORDER BY member.id_member DESC";
}
$query = $dbc->query($sql);
$rows = $query->fetchAll(PDO::FETCH_ASSOC);

include "view/members.inc";

