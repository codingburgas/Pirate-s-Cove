<?php
    $servername = "localhost";
    $username = "root";
    $pass = "";
    $dbName = "the pirate's cove";

    // Create connection
    $conn = new mysqli($servername, $username, $pass, $dbName);

    // Check connection
    if ($conn->connect_error)
        die("Connection failed: " . $conn->connect_error);