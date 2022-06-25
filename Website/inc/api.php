<?php

require "db.php";

$response = [];

$email = $_GET['email'];

if ($conn) {
	$sql = "SELECT * FROM users WHERE email = '". $email ."'";
	$result = mysqli_query($conn, $sql);

	if ($result) {
		header("Content-Type: JSON");

		for ($i = 0; $row = mysqli_fetch_assoc($result); $i++) {
			$response[$i]['id'] = $row['id'];
			$response[$i]['email'] = $row['email'];
			$response[$i]['password'] = $row['password'];
			$response[$i]['item1'] = $row['item1'];
			$response[$i]['item2'] = $row['item2'];
			$response[$i]['item3'] = $row['item3'];
			$response[$i]['item4'] = $row['item4'];
			$response[$i]['item5'] = $row['item5'];
			$response[$i]['item6'] = $row['item6'];
			$response[$i]['item7'] = $row['item7'];
			$response[$i]['item8'] = $row['item8'];
			$response[$i]['item9'] = $row['item9'];
		}

		echo str_replace(array('[', ']'), '', htmlspecialchars(json_encode($response), ENT_NOQUOTES));

		//echo json_encode($response, JSON_PRETTY_PRINT);
	}
}