<?php

session_start();

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ERROR);
include_once "inc/raintpl/rain.tpl.class.php";
include_once "inc/db.php";
$install_path="";
$sm = new RainTPL();

//RAIN TPL ===============================================
raintpl::$tpl_dir = $install_path."templates/"; // template directory
raintpl::$cache_dir = $install_path."cache/"; // cache directory

if (!(isset($_SESSION['ime'])))
{
	header("Location: ./login.php");
	exit();
}

$sql = "SELECT * FROM users WHERE email = '". $_SESSION['ime'] ."'";
$result = mysqli_query($conn, $sql);

while ($row = mysqli_fetch_assoc($result)) {
  $items[] = $row;
}

$sm->assign("items", $items);
$sm->assign("get",$_GET);
$sm->assign("session",$_SESSION);
$sm->display("profile.html");