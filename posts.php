<?php

// Halaman Dashboard setelah login

require 'include/ceklogin.inc';
include "include/init.inc";

//mengambil seluruh posting (admin) atau yang hanya difollow (member)
if ($_SESSION['level'] == 'admin') {
    $sql = "
    SELECT post.id_member, member.fullname_member, post.message from post
    JOIN member ON post.id_member = member.id_member ORDER BY post.id_post DESC";
} else if ($_SESSION['level'] == 'member') {
    $sql = "
    SELECT post.id_member, member.fullname_member, post.message from post
    JOIN member ON post.id_member = member.id_member
    JOIN connection ON post.id_member = connection.id_addmember
    WHERE connection.id_member = '$_SESSION[id]' ORDER BY post.id_post DESC";
}
$rows = $dbc->query($sql);

include "view/posts.inc";

