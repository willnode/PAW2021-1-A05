<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
	<?php include "navbar.inc"; ?>
	<div class="content">
		<div>
			<h1 class="center-text">Daftar Member</h1>
			<?php
			foreach ($rows as $data) :
			?>
				<div class="post">
					<h4 class="memberitem">
						<a href="profile.php?id=<?php echo $data['id_member'] ?>">
							<?php echo $data['fullname_member'] ?>
						</a>
						<?php if ($_SESSION['level'] == 'member') { ?>
							<form action="" method="post">
								<input type="hidden" value="<?php echo $data['id_member'] ?>" name="id_member">
								<input type="hidden" value="<?php echo $data['id_addmember'] ? 'unfollow' : 'follow' ?>" name="action">
								<button class="followbtn"><?php echo $data['id_addmember'] ? 'Unfollow' : 'Follow' ?></button>
							</form>
						<?php } ?>
					</h4>
				</div>
			<?php
			endforeach
			?>
		</div>
	</div>
	<?php include "footer.inc"; ?>
</body>

</html>