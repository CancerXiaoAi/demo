/*
 Navicat MySQL Data Transfer

 Source Server         : 13
 Source Server Type    : MySQL
 Source Server Version : 80021
 Source Host           : localhost:3306
 Source Schema         : store

 Target Server Type    : MySQL
 Target Server Version : 80021
 File Encoding         : 65001

 Date: 27/05/2024 13:58:31
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for book
-- ----------------------------
DROP TABLE IF EXISTS `book`;
CREATE TABLE `book`  (
  `图书编号` char(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `图书类别` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL DEFAULT '计算机',
  `书名` varchar(40) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `作者` char(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `出版社` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `出版时间` date NOT NULL,
  `单价` float(5, 2) NOT NULL,
  `数量` int(0) NULL DEFAULT NULL,
  `折扣` float(3, 2) NULL DEFAULT NULL,
  `封面图片` varchar(40) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL DEFAULT NULL,
  PRIMARY KEY (`图书编号`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = gb2312 COLLATE = gb2312_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of book
-- ----------------------------
INSERT INTO `book` VALUES ('TP.2462', '计算机', '计算机应用基础', '陆大强', '清华大学出版社', '2018-10-19', 45.00, 45, 0.80, NULL);
INSERT INTO `book` VALUES ('TP.2463', '计算机', '计算机网络技术', '林力辉', '清华大学出版社', '2020-10-16', 25.50, 31, 0.80, 'D\\pic\\ll.jpg');
INSERT INTO `book` VALUES ('TP.2525', '计算机', 'PHP高级语言', '王大卫', '中国青年出版社', '2020-06-20', 33.25, 50, 0.80, 'D:\\pic\\js.jpg');
INSERT INTO `book` VALUES ('TP.6625', '计算机', 'JavaScript编程', '谢为民', '中国青年出版社', '2020-08-05', 33.00, 60, 0.80, NULL);
INSERT INTO `book` VALUES ('TP.9501', '计算机', 'Dreamweaver', 'baoLiJia', '高等教育出版社', '2020-08-16', 33.25, 50, 0.80, NULL);
INSERT INTO `book` VALUES ('Ts.3010', '数据库', 'ORACLE', '张小刚', '北京大学出版社', '2019-08-02', 28.00, NULL, NULL, NULL);
INSERT INTO `book` VALUES ('Ts.3035', '数据库', 'MYSQL数据库', '李刚', '北京大学出版社', '2020-12-26', 20.00, 500, 0.80, 'D:\\pic\\jp.jpg');
INSERT INTO `book` VALUES ('Tw.1283', '网页设计', 'DW网站制作', '李华', '人民邮电出版社', '2015-10-01', 27.00, NULL, NULL, NULL);
INSERT INTO `book` VALUES ('Tw.2562', '网页设计', 'ASP网站制作', '胡莉惠', '中国青年出版社', '2020-07-24', 30.50, 50, 0.80, NULL);
INSERT INTO `book` VALUES ('Tw.3020', '网页设计', '网页程序设计', '刘辉', '清华大学出版社', '2019-02-15', 25.00, NULL, NULL, NULL);

-- ----------------------------
-- Table structure for members
-- ----------------------------
DROP TABLE IF EXISTS `members`;
CREATE TABLE `members`  (
  `用户号` char(18) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `姓名` char(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `性别` char(2) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `密码` char(6) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `联系电话` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `注册时间` datetime(0) NULL DEFAULT NULL,
  PRIMARY KEY (`用户号`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = gb2312 COLLATE = gb2312_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of members
-- ----------------------------

SET FOREIGN_KEY_CHECKS = 1;
