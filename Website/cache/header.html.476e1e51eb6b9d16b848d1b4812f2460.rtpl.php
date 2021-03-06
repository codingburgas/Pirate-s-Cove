<?php if(!class_exists('raintpl')){exit;}?><!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>The Pirate Cove</title>
  <link rel="stylesheet" type="text/css" href="assets/styles/style.css">
  <link rel="stylesheet" type="text/css" href="assets/styles/responsiveness/mobile-responsiveness.css">
  <link rel="stylesheet" type="text/css" href="assets/styles/responsiveness/mobile-index.css">
  <link rel="stylesheet" type="text/css" href="assets/styles/responsiveness/mobile-about.css">
  <link rel="stylesheet" type="text/css" href="assets/styles/responsiveness/mobile-registration.css">
  <link rel="stylesheet" type="text/css" href="assets/styles/responsiveness/mobile-profile.css">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
  <link rel="shortcut icon" href="assets/Images/logo.ico" type="image/x-icon">
</head>
<body>

  <nav>
    <ul>
        <?php if( $session["ime"] ){ ?>
          <li class="logo-li"><a href="index.php"><img class="logo" src="assets/Images/logo.png"></a></li>
          <li><a href="index.php">Home</a></li>
          <li><a href="about.php">About Us</a></li>
          <li><a href="profile.php">Profile</a></li>
          <li><a href="inc/logout.inc.php">Logout</a></li>
        <?php }else{ ?>
          <li class="logo-li"><a href="index.php"><img class="logo" src="assets/Images/logo.png"></a></li>
          <li><a href="index.php">Home</a></li>
          <li><a href="about.php">About Us</a></li>
          <li><a href="signup.php">Sign Up</a></li>
          <li><a href="login.php">Log In</a></li>
        <?php } ?>
    </ul>
  </nav>