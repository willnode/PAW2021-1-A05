<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
    <?php include "navbar.inc"; ?>
    <div class="content">
        <div>
            <h1>Post Baru</h1>
            <form method="POST">
                    <div class="field">
                        <label for="title">Pesan</label> <span><?php echo $err['message'] ?? '' ?></span>
                        <textarea name="message" class="input" placeholder="Pesan Post" cols="30" rows="10"></textarea>
                    </div>
                <div><input type="submit" class="submitbtn" value="Kirim" name="submit" id="submit"></div>
            </form>
        </div>
    </div>
    <?php include "footer.inc"; ?>
</body>

</html>