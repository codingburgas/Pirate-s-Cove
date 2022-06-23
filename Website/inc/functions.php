<?php

require "db.php";

function enoughtCharacter($password) {
	$result;
	if (strlen($password) < 4)
		$result = true;
	else
		$result = false;

	return $result;
}

function samePassword ($password, $repassword) {
	$result;

	if (($password === $repassword) === false)
		$result = true;
	else
		$result = false;

	return $result;
}

function emailExists($conn, $email) {
	$sql = "SELECT * FROM users WHERE email = ?";
	$stmt = mysqli_stmt_init($conn);

	if (!mysqli_stmt_prepare($stmt, $sql)) {
		header('Location: ../signup.php?error=stmtfailed');
		exit();
	}
		
	mysqli_stmt_bind_param($stmt, "s", $email);
	mysqli_stmt_execute($stmt);

	$resultData = mysqli_stmt_get_result($stmt);

	if ($row = mysqli_fetch_assoc($resultData)) {
		return $row;
	} else {
		$result = false;
		return $result;
	}

	mysqli_stmt_close($stmt);
}
	

function createUser ($conn, $email, $password) {

		$emailExists = emailExists($conn, $email);

		$result;
		$sql = "INSERT INTO users (email, password) VALUES (?, ?)";
		$stmt = mysqli_stmt_init($conn);

		if (!mysqli_stmt_prepare($stmt, $sql)) {
			header('Location: ../signup.php?error=stmtfailed');
			exit();
		}

		$hashedPassword = password_hash($password, PASSWORD_DEFAULT);
		
		mysqli_stmt_bind_param($stmt, "ss", $email, $hashedPassword);
		mysqli_stmt_execute($stmt);
		mysqli_stmt_close($stmt);


		session_start();
		$_SESSION['ime'] = $emailExists['email'];
		return true;
}

function loginUser($conn, $email, $password) {
		$emailExists = emailExists($conn, $email);

		if ($uidExists === false) {
			header('Location: ../login.php?error=stmtfailed');
			exit();		
		}


		$passwordHashed = $emailExists["password"];
		$checkPassword = password_verify($password, $passwordHashed);

		if ($checkPassword === false) {
			header('Location: ../login.php?error=invalidlogin');
			exit();
			
		}
		else if ($checkPassword === true) {
			session_start();
			$_SESSION['ime'] = $emailExists['email'];
			header('Location: ../settings.php?login=success');
			exit();	
		}		
}