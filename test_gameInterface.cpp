#include "pch.h"
#include "GameInterface.h"

TEST(GIEasy, height) {
	EasyGame obj;
	EXPECT_EQ(obj.getHeight(), 8);
	EXPECT_TRUE(true);
}

TEST(GIEasy, width) {
	EasyGame obj;
	EXPECT_EQ(obj.getWidth(), 8);
	EXPECT_TRUE(true);
}

TEST(GIEasy, mines) {
	EasyGame obj;
	EXPECT_EQ(obj.getMines(), 9);
	EXPECT_TRUE(true);
}

TEST(GIEasy, score) {
	EasyGame obj;
	obj.setScore(12);
	EXPECT_EQ(obj.getScore(), 12);
	EXPECT_TRUE(true);
}

TEST(GIEasy, lost) {
	EasyGame obj;
	obj.setLost(false);
	EXPECT_EQ(obj.getLost(), false);
	EXPECT_TRUE(true);
}

TEST(GIEasy, won) {
	EasyGame obj;
	obj.setWon(true);
	EXPECT_EQ(obj.getWon(), true);
	EXPECT_TRUE(true);
}

TEST(GIMid, height) {
	MediumGame obj;
	EXPECT_EQ(obj.getHeight(), 16);
	EXPECT_TRUE(true);
}

TEST(GIMid, width) {
	MediumGame obj;
	EXPECT_EQ(obj.getWidth(), 16);
	EXPECT_TRUE(true);
}

TEST(GIMid, mines) {
	MediumGame obj;
	EXPECT_EQ(obj.getMines(), 40);
	EXPECT_TRUE(true);
}

TEST(GIMid, score) {
	MediumGame obj;
	obj.setScore(12);
	EXPECT_EQ(obj.getScore(), 12);
	EXPECT_TRUE(true);
}

TEST(GIMid, lost) {
	MediumGame obj;
	obj.setLost(false);
	EXPECT_EQ(obj.getLost(), false);
	EXPECT_TRUE(true);
}

TEST(GIMid, won) {
	MediumGame obj;
	obj.setWon(true);
	EXPECT_EQ(obj.getWon(), true);
	EXPECT_TRUE(true);
}

TEST(GIHard, height) {
	MediumGame obj;
	EXPECT_EQ(obj.getHeight(), 23);
	EXPECT_TRUE(true);
}

TEST(GIHard, width) {
	MediumGame obj;
	EXPECT_EQ(obj.getWidth(), 16);
	EXPECT_TRUE(true);
}

TEST(GIMid, mines) {
	MediumGame obj;
	EXPECT_EQ(obj.getMines(), 60);
	EXPECT_TRUE(true);
}

TEST(GIHard, score) {
	MediumGame obj;
	obj.setScore(12);
	EXPECT_EQ(obj.getScore(), 12);
	EXPECT_TRUE(true);
}

TEST(GIHard, lost) {
	MediumGame obj;
	obj.setLost(false);
	EXPECT_EQ(obj.getLost(), false);
	EXPECT_TRUE(true);
}

TEST(GIHard, won) {
	MediumGame obj;
	obj.setWon(true);
	EXPECT_EQ(obj.getWon(), true);
	EXPECT_TRUE(true);
}