#include "ssd.hpp"
ssd :: ssd(int num_blocks, int bs, int ps, int ssd_cell_type)
{
	int num_pages = bs / ps;
	num_blocks_in_ssd = num_blocks;
	size_of_block = bs;

	current_block_number = 0;
	max_invalid_cell_threshold = 80;
	max_invalid_block_threshold = 80;
	max_invalid_page_threshold = 80;
	block_array = vector < block> (num_blocks, block(num_pages, ps ,ssd_cell_type, 0, NO_WOM));
	for (int i = 0 ; i < num_pages ; i++) {
		block_array[i].setBlockNumber(i);
	}
}

/* buf is initialized by caller */
int ssd :: write_to_disk(uint8_t *buf, int size)
{
	// calculate number of LBN to be updated. (here).
	// check which of them are overwrites (shouldn't have lbn-pbn as LONG_MAX). (l2p.getPBN)
	// invalidate these pages. (block.InvalidatePage()). l2pMap.invalidatePage)

	// allocate new PBNs for all LBNs. (l2pMap.map_lbns_to_pbns)
	// A. get pbn of each new lbn (getPBN())

	// TODO if PBN is of a block marked for gc. request for additional pages.
	// go back to A. asking for new lbns = pbns marked for GC.

	// TODO beyond 4th write, read PBNs, check unprogrammable cells. check number
	// of additional physical pages to be assigned.
	// while goto A, asking for new lbns = unprogrammable cells / page_size.

	// get block on which write has to happen.
	// generate page vector from buf.
	// do write_to_block(block_no, vector_of_pages);

	assert(buf != NULL);
	return 0;
}

/* buf is initialized by caller */
int ssd :: read_from_disk(uint8_t *buf, int size)
{
	assert(buf != NULL);
	return 0;
}

ssd :: ~ssd()
{

}

void ssd :: invokeGC()
{
	// go through all blocks. arrange them in decreasing order of number of invalidated pages.
	// TODO: block.c get interface for getting number of invalid pages in each block.
	// select top X blocks for erasing. get number of valid pages in this block.
	// TODO: block.c get interface for getting vector of valid pages in block.
	// read all valid pages in a buffer.
	// TODO: get interface for reading page data from a block. getPageData(page_no);
	// call write_to_ssd() with buffer read, for all pages in current block. set block status to READY_TO_ERASE
	// set blockStatus to ERASING. reset all pages in block. make sure all pages are invalidated.
	// set blockStatus to EMPTY.
}
