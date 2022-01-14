<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>

    <div class="content">
        <h1>Masuk</h1>
        <span id="log-err"><?php echo $err['match'] ?? '' ?></span>
        <div class="form">
            <form action="login.php" method="POST" class="login">
                <div class="field">
                    <label for="email">Username</label><span><?php echo $err['username'] ?? '' ?></span>
                    <input type="text" class="input" name="username" id="username" placeholder="Username" value="<?php echo htmlspecialchars($_POST['username'] ?? '') ?>">
                </div>
                <div class="field">
                    <label for="password">Password</label><span><?php echo $err['password'] ?? '' ?></span>
                    <input type="password" class="input" id="password" name="password" placeholder="Password" value="<?php echo htmlspecialchars($_POST['password'] ?? '') ?>">
                </div>
                <div class="field">
                    <label for="login">&nbsp;</label>
                    <input type="submit" class="submitbtn" value="Login" name="login" id="login">
                </div>
            </form>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>