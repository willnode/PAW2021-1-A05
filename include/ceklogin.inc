<?php
session_start(); //memulai session
if (!isset($_SESSION['level'])) {
    header("location:login.php"); //akan diarahkan ke halaman login.php
    exit;
}
