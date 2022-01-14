<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div>
            <h1>Edit Profil</h1>
            <div class="form">
                <!-- form untuk mengedit informasi profile -->
                <form action="edit_profile.php" method="POST" class="login" enctype="multipart/form-data">

                    <hr>
                    <h5>Ubah data berikut Jika ingin diganti</h5>
                    <div class="field">
                        <label for="fullname">Nama Lengkap</label> <span><?php echo $err['fullname'] ?? '' ?></span>
                        <input type="text" class="input" name="fullname" id="fullname" placeholder="Nama Lengkap" value="<?php echo htmlspecialchars($_POST['fullname'] ?? $_SESSION['fullname']) ?>">
                    </div>
                    <div class="field">
                        <label for="username">Username</label><span><?php echo $err['username'] ?? '' ?></span>
                        <input type="text" class="input" name="username" id="username" placeholder="Username" value="<?php echo htmlspecialchars($_POST['username'] ?? $_SESSION['username']) ?>">
                    </div>
                    <div class="field">
                        <label for="email">Email</label><span><?php echo $err['email'] ?? '' ?></span>
                        <input type="text" class="input" name="email" id="email" placeholder="Email" value="<?php echo htmlspecialchars($_POST['email'] ?? $_SESSION['email']) ?>">
                    </div>
                    <div class="field">
                        <label for="nohp">Nomor HP</label><span><?php echo $err['nohp'] ?? '' ?></span>
                        <input type="text" class="input" name="nohp" id="nohp" placeholder="Nomor Hp" value="<?php echo htmlspecialchars($_POST['nohp'] ?? $_SESSION['nohp']) ?>">
                    </div>
                    <hr>
                    <h5>Ketik Password Baru Jika ingin diganti</h5>
                    <div class="field">
                        <label for="password">Password</label> <span><?php echo $err['password'] ?? '' ?></span>
                        <input type="password" autocomplete="new-password" class="input" id="password" name="password" placeholder="Password" value="">
                    </div>
                    <div class="field">
                        <label for="confirm">Konfirmasi Password</label> <span><?php echo $err['confirm'] ?? '' ?></span>
                        <input type="password" autocomplete="new-password" class="input" name="confirm" id="confirm" placeholder="Password Lagi" value="">
                    </div>
                    <hr>
                    <h5>Upload Foto Baru Jika ingin diganti</h5>
                    <img class="pp" src="<?php echo "image/profile/" . ($_SESSION['photo'] ?: 'profile.png') ?>" alt="profil">
                    <div class="field">
                        <label for="avatar">Photo</label> <span><?php echo $err['photo'] ?? '' ?></span>
                        <input type="file" class="ava" name="photo" id="photo">
                        <div class="field">
                            <label for="submit">&nbsp;</label>
                            <input type="submit" class="submitbtn" value="Simpan" name="submit" id="submit">
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>