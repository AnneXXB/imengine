-- phpMyAdmin SQL Dump
-- version 4.2.7.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 2016-12-30 15:26:51
-- 服务器版本： 5.6.17
-- PHP Version: 5.5.36

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `nebula_platform`
--

-- --------------------------------------------------------

--
-- 表的结构 `apps`
--

CREATE TABLE IF NOT EXISTS `apps` (
`app_id` int(11) NOT NULL,
  `org_id` int(11) NOT NULL,
  `app_name` varchar(256) NOT NULL,
  `product_name` varchar(256) NOT NULL,
  `descr` varchar(256) NOT NULL DEFAULT '',
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `created_at` int(11) NOT NULL DEFAULT '0',
  `updated_at` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

-- --------------------------------------------------------

--
-- 表的结构 `app_configs`
--

CREATE TABLE IF NOT EXISTS `app_configs` (
`app_id` int(11) NOT NULL,
  `config_key` int(11) NOT NULL,
  `config_value` int(11) NOT NULL,
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `created_at` int(11) NOT NULL,
  `updated_at` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `app_ios_push_certs`
--

CREATE TABLE IF NOT EXISTS `app_ios_push_certs` (
`cert_id` int(11) NOT NULL,
  `app_id` int(11) NOT NULL,
  `bundle_id` int(11) NOT NULL,
  `cert_type` int(11) NOT NULL,
  `cert_memo` int(11) NOT NULL,
  `uploaded` int(11) NOT NULL,
  `expired` int(11) NOT NULL,
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `created_at` int(11) NOT NULL,
  `updated_at` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `app_keys`
--

CREATE TABLE IF NOT EXISTS `app_keys` (
  `app_id` int(11) NOT NULL,
  `app_key` varchar(256) NOT NULL,
  `app_secret` varchar(256) NOT NULL,
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `created_at` int(11) NOT NULL,
  `refresher` int(11) NOT NULL,
  `refreshed_at` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 表的结构 `orgs`
--

CREATE TABLE IF NOT EXISTS `orgs` (
`org_id` int(11) NOT NULL,
  `account_name` varchar(64) NOT NULL,
  `passwd` char(32) NOT NULL,
  `org_name` varchar(256) NOT NULL,
  `mail` varchar(64) NOT NULL,
  `mobile` varchar(32) NOT NULL,
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `created_at` int(11) NOT NULL,
  `updated_at` int(11) NOT NULL
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

-- --------------------------------------------------------

--
-- 表的结构 `users`
--

CREATE TABLE IF NOT EXISTS `users` (
`id` bigint(20) NOT NULL,
  `app_id` int(11) NOT NULL DEFAULT '1',
  `user_id` varchar(256) NOT NULL,
  `user_token` varchar(256) NOT NULL,
  `avatar` varchar(256) NOT NULL DEFAULT '',
  `nick` varchar(256) NOT NULL DEFAULT '',
  `is_active` tinyint(4) NOT NULL DEFAULT '0',
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `created_at` bigint(20) NOT NULL DEFAULT '0',
  `updated_at` bigint(20) NOT NULL DEFAULT '0'
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=11 ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `apps`
--
ALTER TABLE `apps`
 ADD PRIMARY KEY (`app_id`);

--
-- Indexes for table `app_configs`
--
ALTER TABLE `app_configs`
 ADD PRIMARY KEY (`app_id`);

--
-- Indexes for table `app_ios_push_certs`
--
ALTER TABLE `app_ios_push_certs`
 ADD PRIMARY KEY (`cert_id`);

--
-- Indexes for table `app_keys`
--
ALTER TABLE `app_keys`
 ADD PRIMARY KEY (`app_id`);

--
-- Indexes for table `orgs`
--
ALTER TABLE `orgs`
 ADD PRIMARY KEY (`org_id`), ADD UNIQUE KEY `account_name` (`account_name`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
 ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `apps`
--
ALTER TABLE `apps`
MODIFY `app_id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `app_configs`
--
ALTER TABLE `app_configs`
MODIFY `app_id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `app_ios_push_certs`
--
ALTER TABLE `app_ios_push_certs`
MODIFY `cert_id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `orgs`
--
ALTER TABLE `orgs`
MODIFY `org_id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=11;

