<!DOCTYPE html>
<html lang="en">
<?php include "head.inc" ?>

<body>
	<?php include "navbar.inc"; ?>
	<div class="content">
		<div>
			<h1 class="center-text">Dashboard</h1>
			<?php

			foreach ($rows as $data) :
			?>
				<div class="post">
					<h4 class="memberitem">
						<a href="profile.php?id=<?php echo $data['id_member'] ?>">
							<?php echo $data['fullname_member'] ?>
						</a>
					</h4>
					<p><?php echo $data['message'] ?></p>
				</div>
			<?php
			endforeach
			?>
		</div>
	</div>
	<?php include "footer.inc"; ?>
</body>

</html>