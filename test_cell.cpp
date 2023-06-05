#include "pch.h"
#include "Cell.h"


TEST(Cell, X) {
	Closed obj(1, 1);
	EXPECT_EQ(obj.getX(), 1);
	EXPECT_TRUE(true);
}

TEST(Cell, Y) {
	Closed obj(1, 1);
	EXPECT_EQ(obj.getY(), 1);
	EXPECT_TRUE(true);
}

TEST(Cell, getMine) {
	Closed obj(1, 1);
	obj.setMine(true);
	EXPECT_EQ(true, obj.isMine());

}

TEST(Cell, getMIne2) {
	Closed obj(1, 1);
	obj.setMine(false);
	EXPECT_EQ(false, obj.isMine());
}

TEST(Cell, getFlag) {
	Closed obj(1, 1);
	obj.setFlag(true);
	EXPECT_EQ(true, obj.isFlag());
}

TEST(Cell, getFlag2) {
	Closed obj(1, 1);
	obj.setFlag(false);
	EXPECT_EQ(false, obj.isFlag());
}

TEST(Cell, getOpen) {
	Closed obj(1, 1);
	obj.setOpen(true);
	EXPECT_EQ(true, obj.isOpen());
}

TEST(Cell, getOpen2) {
	Closed obj(1, 1);
	obj.setOpen(false);
	EXPECT_EQ(false, obj.isOpen());
}

TEST(Cell, Mine) {
	Mine obj(1, 1);
	EXPECT_EQ(true, obj.isMine());
}

TEST(Cell, Mine2) {
	Mine obj(1, 1);
	EXPECT_EQ(true, obj.isOpen());
}

TEST(Cell, MIne3) {
	Mine obj(1, 1);
	EXPECT_EQ(false, obj.isFlag());
}

TEST(Cell, Flag) {
	Flag obj(1, 1, 1, false);
	EXPECT_EQ(true, obj.isFlag());
}

TEST(Cell, Flag2) {
	Flag obj2(1, 1, 1, true);
	EXPECT_EQ(true, obj2.isMine());
}

TEST(Cell, Flag3) {
	Flag obj(1, 1, 1, false);
	EXPECT_EQ(true, obj.isOpen());
}

TEST(Cell, Numbered) {
	Numbered obj(1, 1, 1);
	EXPECT_EQ(true, obj.isOpen());
}

TEST(Cell, Numbered2) {
	Numbered obj(1, 1, 1);
	EXPECT_EQ(false, obj.isFlag());
}

TEST(Cell, Numbered3) {
	Numbered obj(1, 1, 1);
	EXPECT_EQ(false, obj.isMine());
}

TEST(Cell, AdjacentMines) {
	Numbered obj(1, 1, 0);
	obj.setAdjacentMines(4);
	EXPECT_EQ(4, obj.getAdjacentMines());

}