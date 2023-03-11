struct Location {
	int row;
	int col;
	Location(int r = 0, int c = 0) {
		row = r;
		col = c;
	}
	bool isNeighbor(Location& p) {
		return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) ||
			(col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
	bool operator==(Location& p) {
		return row == p.row && col == p.col;
	}
};