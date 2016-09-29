#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <libgraph/ConnectManagers/ConnectManager.h>
#include <libgraph/ConnectStorages/AdjacencyMatrixConnectStorage.h>

using namespace libgraph;

class ConnectManagerTest : public ::testing::Test {
protected:
	AdjacencyMatrixConnectStorage *storage = new AdjacencyMatrixConnectStorage(10);
	ConnectManager *manager;
	void SetUp() {
		manager = new ConnectManager(storage);
	}
	void TearDown() {
		delete storage;
		delete manager;
	}
};

TEST_F(ConnectManagerTest, testConnectDirection) {
	manager->settings.connectConsiderDirection = true;
	manager->settings.lookupConsiderDirection = true;

	manager->connect(1, 3);
	ASSERT_TRUE(manager->areConnected(1, 3));
	ASSERT_FALSE(manager->areConnected(3, 1));
	manager->connect(4, 6);
	ASSERT_TRUE(manager->areConnected(4, 6));
	ASSERT_FALSE(manager->areConnected(6, 4));

	storage->clear();
	manager->settings.connectConsiderDirection = false;
	manager->connect(1, 3);
	ASSERT_TRUE(manager->areConnected(1, 3));
	ASSERT_TRUE(manager->areConnected(3, 1));
	manager->connect(4, 6);
	ASSERT_TRUE(manager->areConnected(4, 6));
	ASSERT_TRUE(manager->areConnected(6, 4));
}

TEST_F(ConnectManagerTest, testLookupDirection) {
	manager->settings.connectConsiderDirection = true;
	manager->settings.lookupConsiderDirection = true;

	manager->connect(1, 3);
	ASSERT_TRUE(manager->areConnected(1, 3));
	ASSERT_FALSE(manager->areConnected(3, 1));
	manager->connect(4, 6);
	ASSERT_TRUE(manager->areConnected(4, 6));
	ASSERT_FALSE(manager->areConnected(6, 4));

	storage->clear();
	manager->settings.lookupConsiderDirection = false;
	manager->connect(1, 3);
	ASSERT_TRUE(manager->areConnected(1, 3));
	ASSERT_TRUE(manager->areConnected(3, 1));
	manager->connect(4, 6);
	ASSERT_TRUE(manager->areConnected(4, 6));
	ASSERT_TRUE(manager->areConnected(6, 4));
}
