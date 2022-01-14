<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content profile-page">
        <div>
            <h1 class="center-text">Profile</h1>
            <div class="left-text">
                <img class="pp" src="<?php echo "image/profile/" . ($result['photo_member'] ?: 'profile.png') ?>" alt="profil">
                <div>
                    <h2><?php echo htmlspecialchars($result['fullname_member']); ?></h2>
                    <?php if ($_SESSION['level'] == 'member') { ?>
                        <form action="" method="post">
                            <input type="hidden" value="<?php echo $result['id_member'] ?>" name="id_member">
                            <input type="hidden" value="<?php echo $follow ? 'unfollow' : 'follow' ?>" name="action">
                            <button class="followbtn"><?php echo $follow ? 'Unfollow' : 'Follow' ?></button>
                        </form>
                    <?php } ?>
                </div>
            </div>
            <div class="right-text">
                <h3>Daftar Post Terkini</h3>
                <ol>
                    <?php
                    $sql = "
                        SELECT post.id_member, member.fullname_member, post.message from post
                        JOIN member ON post.id_member = member.id_member
                        WHERE member.id_member = :id ORDER BY post.id_post DESC";
                    //query untuk thread list yang pernah di buat user client
                    $query = $dbc->prepare($sql);
                    $query->bindValue(":id", $_GET['id'] ?? $_SESSION['id']);
                    $query->execute();
                    ?>
                    <?php
                    //menampilkan hasil query
                    foreach ($query as $data) {
                    ?>
                        <div class="post">
                            <h4>
                                <a href="profile.php?id=<?php echo $data['id_member'] ?>">
                                    <?php echo $data['fullname_member'] ?>
                                </a>
                            </h4>
                            <p><?php echo $data['message'] ?></p>
                        </div>
                    <?php
                    }
                    ?>
                </ol>
            </div>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>