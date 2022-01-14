<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div>
            <h1>Daftar</h1>
            <div class="form">
                <!-- Form register -->
                <form action="register.php" method="POST" class="login" enctype="multipart/form-data">
                    <div class="field">
                        <label for="fullname">Nama Lengkap</label> <span><?php echo $err['fullname'] ?? '' ?></span>
                        <input type="text" class="input" name="fullname" id="fullname" placeholder="Nama Lengkap" value="<?php echo htmlspecialchars($_POST['fullname'] ?? '') ?>">
                    </div>
                    <div class="field">
                        <label for="username">Username</label><span><?php echo $err['username'] ?? '' ?></span>
                        <input type="text" class="input" name="username" id="username" placeholder="Username" value="<?php echo htmlspecialchars($_POST['username'] ?? '') ?>">
                    </div>
                    <div class="field">
                        <label for="email">Email</label><span><?php echo $err['email'] ?? '' ?></span>
                        <input type="text" class="input" name="email" id="email" placeholder="Email" value="<?php echo htmlspecialchars($_POST['email'] ?? '') ?>">
                    </div>
                    <div class="field">
                        <label for="nohp">Nomor HP</label><span><?php echo $err['nohp'] ?? '' ?></span>
                        <input type="text" class="input" name="nohp" id="nohp" placeholder="Nomor Hp" value="<?php echo htmlspecialchars($_POST['nohp'] ?? '') ?>">
                    </div>
                    <div class="field">
                        <label for="password">Password</label> <span><?php echo $err['password'] ?? '' ?></span>
                        <input type="password" class="input" id="password" name="password" placeholder="Password" value="<?php echo htmlspecialchars($_POST['password'] ?? '') ?>">
                    </div>
                    <div class="field">
                        <label for="confirm">Konfirmasi Password</label> <span><?php echo $err['confirm'] ?? '' ?></span>
                        <input type="password" class="input" name="confirm" id="confirm" placeholder="Password Lagi" value="<?php echo htmlspecialchars($_POST['confirm'] ?? '') ?>">
                    </div>
                    <div class="field">
                        <label for="type">Tipe</label> <span><?php echo $err['type'] ?? '' ?></span>
                        <select class="input" name="type" id="type">
                            <option value="member">Member</option>
                            <option value="admin">Admin</option>
                        </select>
                    </div>
                    <div class="field">
                        <label for="submit">&nbsp;</label>
                        <input type="submit" class="submitbtn" value="Submit" name="submit" id="submit">
                    </div>
                </form>
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>