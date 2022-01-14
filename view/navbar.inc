<?php
if (!isset($_SESSION)) {
    // inisialisasi sesi
    session_start();
}
?>
<div class="navbar">
    <div class="left-bar">
        <ol>
            <?php
            //cek session aktif
            if (!isset($_SESSION['level'])) {
            ?>
                <li><a href="index.php">Beranda</a></li>
            <?php
            } else {
            ?>
                <li><a href="posts.php">Postingan</a></li>
                <li><a href="members.php">List Member</a></li>
                <?php if ($_SESSION['level'] == 'member') { ?>
                    <li><a href="submit.php">Post Baru</a></li>
                <?php } ?>
            <?php
            }
            ?>
        </ol>
    </div>
    <div class="right-bar">
        <?php
        //cek session aktif
        if (!isset($_SESSION['level'])) {
        ?>
            <ol>
                <li><a href="login.php">Masuk</a></li>
                <li><a href="register.php">Daftar</a></li>
            </ol>
        <?php
        } else {
        ?>
            <div class="dropdown">
                <button class="dropbtn"><?php echo $_SESSION['fullname'] ?></button>
                <div class="dropdown-content">
                    <a href="profile.php">Lihat Profil</a>
                    <a href="edit_profile.php">Edit Profil</a>
                    <a href="logout.php">Logout</a>
                </div>
            </div>
        <?php
        }
        ?>
    </div>
</div>