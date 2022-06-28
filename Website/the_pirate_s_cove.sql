-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 23, 2022 at 10:57 PM
-- Server version: 10.4.21-MariaDB
-- PHP Version: 8.0.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `the pirate's cove`
--

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `item1` varchar(255) NOT NULL DEFAULT 'locked',
  `item2` varchar(255) NOT NULL DEFAULT 'locked',
  `item3` varchar(255) NOT NULL DEFAULT 'locked',
  `item4` varchar(255) NOT NULL DEFAULT 'locked',
  `item5` varchar(255) NOT NULL DEFAULT 'locked',
  `item6` varchar(255) NOT NULL DEFAULT 'locked',
  `item7` varchar(255) NOT NULL DEFAULT 'locked',
  `item8` varchar(255) NOT NULL DEFAULT 'locked',
  `item9` varchar(255) NOT NULL DEFAULT 'locked'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `email`, `password`, `item1`, `item2`, `item3`, `item4`, `item5`, `item6`, `item7`, `item8`, `item9`) VALUES
(3, 'user@user.com', '$2y$10$ztSz1He2MUVLSW06iL7YbO2HT0vbhrTwpuC4zpS1f/UIG3xRPH6C.', 'locked', 'locked', 'locked', 'locked', 'locked', 'locked', 'locked', 'locked', 'locked'),
(4, 'admin@admin.com', '$2y$10$tEP7qYZFbRF31Z9hWChCFesbX8RWa8ou6PcZ2awmZUo35ype7N/ES', 'locked', 'locked', 'locked', 'locked', 'locked', 'locked', 'locked', 'locked', 'locked');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
