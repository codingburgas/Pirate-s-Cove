<?php

session_start();

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ERROR);
include_once "inc/raintpl/rain.tpl.class.php";
$install_path="";
$sm = new RainTPL();

//RAIN TPL ===============================================
raintpl::$tpl_dir = $install_path."templates/"; // template directory
raintpl::$cache_dir = $install_path."cache/"; // cache directory

if(isset($_GET["error"])) {
	if ($_GET["error"] == "lowcharacters") {
		$msg = "<p class='error'>Your password should be with more than 3 characters</p>";
	}
	if ($_GET["error"] == "notsamepwd") {
		$msg = "<p class='error'>Your passwords does not match</p>";
	}
}

if (!(isset($_SESSION['ime'])))
{
	header("Location: ./login.php");
	exit();
}

$sm->assign("get",$_GET);
$sm->assign("session",$_SESSION);
$sm->display("settings.html");