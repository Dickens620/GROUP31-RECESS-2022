-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Feb 01, 2022 at 08:29 AM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `kcpms`
CREATE DATABASE kcpms;
USE kcpms;
--

-- --------------------------------------------------------

--
-- Table structure for table `assignments`
--

CREATE TABLE `assignments` (
  `id` int(11) NOT NULL,
  `assignment` text NOT NULL,
  `startDate` date NOT NULL,
  `startTime` time NOT NULL,
  `endDate` date NOT NULL,
  `endTime` time NOT NULL,
  `status` int(11) NOT NULL DEFAULT 1,
  `created_on` timestamp NOT NULL DEFAULT current_timestamp(),
  `created_by` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `assignments`
--

INSERT INTO `assignments` (`id`, `assignment`, `startDate`, `startTime`, `endDate`, `endTime`, `status`, `created_on`, `created_by`) VALUES
(1, 'ABCDEF', '2022-01-31', '01:11:00', '2022-01-31', '10:00:00', 1, '2022-01-30 10:24:53', NULL),
(2, 'DAGT', '2022-01-01', '23:30:00', '2022-02-27', '19:36:00', 1, '2022-01-30 10:36:26', NULL),
(3, 'ADECF', '2022-01-06', '23:32:00', '2022-01-02', '23:34:00', 1, '2022-01-30 20:31:46', NULL),
(4, 'assign', '2022-02-22', '09:00:00', '2022-02-22', '11:00:00', 1, '2022-01-31 09:01:54', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `assignment_attempts`
--

CREATE TABLE `assignment_attempts` (
  `id` int(11) NOT NULL,
  `pupil_id` int(11) DEFAULT NULL,
  `assignment_id` int(11) DEFAULT NULL,
  `start_time` time DEFAULT NULL,
  `end_time` time DEFAULT NULL,
  `score` decimal(10,0) DEFAULT NULL,
  `start_date` date DEFAULT NULL,
  `end_date` date DEFAULT NULL,
  `comment` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `assignment_attempts`
--

INSERT INTO `assignment_attempts` (`id`, `pupil_id`, `assignment_id`, `start_time`, `end_time`, `score`, `start_date`, `end_date`, `comment`) VALUES
(1, 1, 1, '13:00:00', '13:30:00', '100', '2022-01-30', '2022-01-30', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `pupils`
--

CREATE TABLE `pupils` (
  `id` int(11) NOT NULL,
  `fname` text DEFAULT NULL,
  `lname` text DEFAULT NULL,
  `phone_no` text DEFAULT NULL,
  `user_code` text DEFAULT NULL,
  `active_flag` int(11) NOT NULL DEFAULT 1,
  `del_flag` int(11) NOT NULL DEFAULT 0,
  `status` text NOT NULL DEFAULT 'active'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `pupils`
--

INSERT INTO `pupils` (`id`, `fname`, `lname`, `phone_no`, `user_code`, `active_flag`, `del_flag`, `status`) VALUES
(1, 'Daaki', 'Benjamin richard', '0756291975', '1368', 1, 0, 'Activated'),
(4, 'Gabula', 'John Stev', '25618101', '4gftu4', 1, 0, 'Activated'),
(6, 'Akankwatsa ', 'Dickens', '0703099355', '8907', 1, 0, 'Activated'),
(7, 'Karungi ', 'Elizabeth', '0780777426', '6y6y', 1, 0, 'Activated'),
(8, 'Alayo', 'Ruth', '078983091334', 'tyyh8282', 1, 0, 'Activated'),
(9, 'mary ', 'nasabagwa', '0989', '', 1, 0, 'Activated'),
(13, 'Mugaru', 'Hakim', '087609966', '5t5t5t', 1, 0, 'Activated'),
(14, 'Nsabagwa ', 'Barbra', '087654356', '4r4r', 1, 0, 'active'),
(15, 'ORACH', 'JULIUS', '0777252245', '8532', 1, 0, 'active'),
(16, 'Mutungi ', 'Ambrozio', '0780675453', '3e3e', 1, 0, 'Activated');

-- --------------------------------------------------------

--
-- Table structure for table `teachers`
--

CREATE TABLE `teachers` (
  `id` int(11) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `fname` varchar(255) NOT NULL,
  `lname` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `teachers`
--

INSERT INTO `teachers` (`id`, `email`, `password`, `fname`, `lname`) VALUES
(1, 'admin@example.com', '25d55ad283aa400af464c76d713c07ad', 'Admin', 'Real'),
(2, 'admin2@example.com', '25d55ad283aa400af464c76d713c07ad', 'Gabula', 'Stephen');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `assignments`
--
ALTER TABLE `assignments`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `assignment_attempts`
--
ALTER TABLE `assignment_attempts`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `pupils`
--
ALTER TABLE `pupils`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `teachers`
--
ALTER TABLE `teachers`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `assignments`
--
ALTER TABLE `assignments`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `assignment_attempts`
--
ALTER TABLE `assignment_attempts`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `pupils`
--
ALTER TABLE `pupils`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `teachers`
--
ALTER TABLE `teachers`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
