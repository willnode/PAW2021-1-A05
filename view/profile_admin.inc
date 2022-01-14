<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content profile-page">
        <div>
            <h1 class="center-text">Profile</h1>
            <div class="left-text">
                <img class="pp" src="<?php echo "image/profile/" . ($result['photo_admin'] ?: 'profile.png') ?>" alt="profil">
                <div>
                    <h2><?php echo htmlspecialchars($result['fullname_admin']); ?></h2>
                </div>
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>