#include <nano/lib/blocks.hpp>

#include <gtest/gtest.h>
namespace nano
{
void cleanup_test_directories_on_exit ();
void force_nano_test_network ();
}

int main (int argc, char ** argv)
{
	nano::force_nano_test_network ();
	nano::block_memory_pool_cleanup_guard block_memory_pool_cleanup_guard;
	testing::InitGoogleTest (&argc, argv);
	auto res = RUN_ALL_TESTS ();
	nano::cleanup_test_directories_on_exit ();
	return res;
}
