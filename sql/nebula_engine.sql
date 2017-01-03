-- phpMyAdmin SQL Dump
-- version 4.2.7.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 2016-12-30 15:14:12
-- 服务器版本： 5.6.17
-- PHP Version: 5.5.36

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `nebula_engine`
--

-- --------------------------------------------------------

--
-- 表的结构 `files`
--

CREATE TABLE IF NOT EXISTS `files` (
`id` bigint(20) NOT NULL,
  `access_salt` text NOT NULL,
  `upload_key` text NOT NULL,
  `is_uploaded` tinyint(1) NOT NULL DEFAULT '0',
  `size` bigint(20) NOT NULL DEFAULT '0',
  `name` varchar(255) DEFAULT ''
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `file_parts`
--

CREATE TABLE IF NOT EXISTS `file_parts` (
`id` bigint(20) NOT NULL,
  `file_id` bigint(20) NOT NULL,
  `number` int(11) NOT NULL,
  `size` int(11) NOT NULL,
  `upload_key` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `groups`
--

CREATE TABLE IF NOT EXISTS `groups` (
`id` bigint(20) NOT NULL,
  `app_id` int(11) NOT NULL DEFAULT '1',
  `group_id` varchar(256) NOT NULL,
  `creator_user_id` varchar(256) NOT NULL,
  `client_group_id` bigint(20) NOT NULL,
  `title` varchar(255) NOT NULL,
  `avatar` varchar(255) NOT NULL DEFAULT '',
  `topic` varchar(255) NOT NULL DEFAULT '',
  `about` text NOT NULL,
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `created_at` bigint(20) NOT NULL,
  `updated_at` bigint(20) NOT NULL,
  `title_changer_user_id` varchar(256) NOT NULL DEFAULT '',
  `title_changed_at` bigint(20) NOT NULL DEFAULT '0',
  `avatar_changer_user_id` varchar(256) NOT NULL DEFAULT '',
  `avatar_changed_at` bigint(20) NOT NULL DEFAULT '0'
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=11 ;

-- --------------------------------------------------------

--
-- 表的结构 `group_invite_tokens`
--

CREATE TABLE IF NOT EXISTS `group_invite_tokens` (
`id` bigint(20) NOT NULL,
  `app_id` int(11) NOT NULL DEFAULT '1',
  `creator_id` varchar(256) NOT NULL,
  `group_id` varchar(256) NOT NULL,
  `revoked_at` int(11) NOT NULL,
  `token` int(11) NOT NULL,
  `created_at` int(11) NOT NULL,
  `deleted_at` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- 表的结构 `group_messages`
--

CREATE TABLE IF NOT EXISTS `group_messages` (
`id` bigint(20) NOT NULL,
  `app_id` int(11) NOT NULL DEFAULT '1',
  `sender_user_id` varchar(256) NOT NULL,
  `peer_id` varchar(256) NOT NULL,
  `peer_type` tinyint(4) NOT NULL,
  `client_message_id` bigint(20) NOT NULL,
  `message_peer_seq` bigint(20) NOT NULL,
  `message_content_type` int(11) NOT NULL,
  `message_content_data` varchar(10240) NOT NULL DEFAULT '',
  `passthrough_data` varchar(10240) NOT NULL DEFAULT '',
  `status` tinyint(4) NOT NULL,
  `created_at` bigint(20) NOT NULL,
  `updated_at` bigint(20) NOT NULL
) ENGINE=InnoDB  DEFAULT CHARSET=ucs2 AUTO_INCREMENT=42 ;

-- --------------------------------------------------------

--
-- 表的结构 `group_users`
--

CREATE TABLE IF NOT EXISTS `group_users` (
`id` bigint(20) NOT NULL,
  `app_id` int(11) NOT NULL DEFAULT '1',
  `group_id` varchar(256) NOT NULL,
  `user_id` varchar(256) NOT NULL,
  `is_admin` tinyint(4) NOT NULL,
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `invited_at` bigint(20) NOT NULL,
  `inviter_user_id` varchar(256) NOT NULL,
  `joined_at` bigint(20) NOT NULL,
  `created_at` bigint(20) NOT NULL,
  `updated_at` bigint(20) NOT NULL
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=20 ;

-- --------------------------------------------------------

--
-- 表的结构 `history_messages`
--

CREATE TABLE IF NOT EXISTS `history_messages` (
`id` bigint(20) NOT NULL,
  `app_id` int(11) NOT NULL DEFAULT '1',
  `sender_user_id` varchar(256) NOT NULL,
  `peer_id` varchar(256) NOT NULL,
  `peer_type` tinyint(4) NOT NULL,
  `client_message_id` bigint(20) NOT NULL,
  `message_peer_seq` bigint(20) NOT NULL,
  `message_content_type` int(11) NOT NULL,
  `message_content_data` varchar(10240) NOT NULL DEFAULT '',
  `passthrough_data` varchar(10240) NOT NULL DEFAULT '',
  `status` tinyint(4) NOT NULL,
  `created_at` bigint(20) NOT NULL,
  `updated_at` bigint(20) NOT NULL
) ENGINE=InnoDB  DEFAULT CHARSET=ucs2 AUTO_INCREMENT=110 ;

-- --------------------------------------------------------

--
-- 表的结构 `seq_updates_ngen`
--

CREATE TABLE IF NOT EXISTS `seq_updates_ngen` (
  `user_id` varchar(255) NOT NULL,
  `seq` bigint(20) NOT NULL,
  `timestamp` bigint(20) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 表的结构 `user_dialogs`
--

CREATE TABLE IF NOT EXISTS `user_dialogs` (
`id` int(11) NOT NULL,
  `app_id` int(11) NOT NULL DEFAULT '1',
  `user_id` varchar(256) NOT NULL,
  `peer_id` varchar(256) NOT NULL,
  `peer_type` tinyint(4) NOT NULL,
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `created_at` bigint(20) NOT NULL,
  `updated_at` bigint(20) NOT NULL
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=52 ;

-- --------------------------------------------------------

--
-- 表的结构 `user_messages`
--

CREATE TABLE IF NOT EXISTS `user_messages` (
`id` int(11) NOT NULL,
  `app_id` int(11) NOT NULL DEFAULT '1',
  `message_id` bigint(20) NOT NULL,
  `user_id` varchar(256) NOT NULL,
  `message_seq` bigint(20) NOT NULL,
  `sender_user_id` varchar(256) NOT NULL,
  `peer_id` varchar(256) NOT NULL,
  `peer_type` tinyint(4) NOT NULL,
  `message_peer_seq` bigint(20) NOT NULL,
  `status` tinyint(4) NOT NULL,
  `created_at` bigint(20) NOT NULL,
  `updated_at` bigint(20) NOT NULL
) ENGINE=InnoDB  DEFAULT CHARSET=ucs2 AUTO_INCREMENT=79 ;

-- --------------------------------------------------------

--
-- 表的结构 `user_sequence`
--

CREATE TABLE IF NOT EXISTS `user_sequence` (
`id` bigint(20) NOT NULL,
  `user_id` varchar(255) NOT NULL,
  `seq` bigint(20) NOT NULL,
  `header` bigint(20) NOT NULL,
  `data` blob,
  `created_at` bigint(20) NOT NULL
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=101 ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `files`
--
ALTER TABLE `files`
 ADD PRIMARY KEY (`id`), ADD UNIQUE KEY `id` (`id`);

--
-- Indexes for table `file_parts`
--
ALTER TABLE `file_parts`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `groups`
--
ALTER TABLE `groups`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `group_invite_tokens`
--
ALTER TABLE `group_invite_tokens`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `group_messages`
--
ALTER TABLE `group_messages`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `group_users`
--
ALTER TABLE `group_users`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `history_messages`
--
ALTER TABLE `history_messages`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `seq_updates_ngen`
--
ALTER TABLE `seq_updates_ngen`
 ADD PRIMARY KEY (`user_id`), ADD UNIQUE KEY `user_id` (`user_id`), ADD KEY `user_id_2` (`user_id`);

--
-- Indexes for table `user_dialogs`
--
ALTER TABLE `user_dialogs`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user_messages`
--
ALTER TABLE `user_messages`
 ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user_sequence`
--
ALTER TABLE `user_sequence`
 ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `files`
--
ALTER TABLE `files`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `file_parts`
--
ALTER TABLE `file_parts`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `groups`
--
ALTER TABLE `groups`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `group_invite_tokens`
--
ALTER TABLE `group_invite_tokens`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `group_messages`
--
ALTER TABLE `group_messages`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=42;
--
-- AUTO_INCREMENT for table `group_users`
--
ALTER TABLE `group_users`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=20;
--
-- AUTO_INCREMENT for table `history_messages`
--
ALTER TABLE `history_messages`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=110;
--
-- AUTO_INCREMENT for table `user_dialogs`
--
ALTER TABLE `user_dialogs`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=52;
--
-- AUTO_INCREMENT for table `user_messages`
--
ALTER TABLE `user_messages`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=79;
--
-- AUTO_INCREMENT for table `user_sequence`
--
ALTER TABLE `user_sequence`
MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=101;

