#include <stdio.h>
//HI THERE I MADE THIS CHANGE 
int rotateRight(int x, int n) {
	int sign_bit = (~n+1) >> 31; //0 for 0, -1 for rest
  	int shift_size = (32 + (~n+1)) & sign_bit;
  	int all_ones = ~0;
  	int a = (all_ones >> n) << n;
  	a = ~a;
  	int shifted_part = (x & a) << shift_size;
  	int clear_bits = ~((sign_bit >> shift_size) << shift_size);
  	x = (x>>n) & (clear_bits);
  	return x | shifted_part;

}

int main() {

	int ans = rotateRight(0x3, 0);
	printf("%d %08x\n",ans, ans);
	return 0;
}



 // I EDITED THIS
 /*
  int shift_size = 32 + (~n+1);
  int shift_part = (x >> shift_size);
  int a = ~(0x8 >> (shift_size+ (~1+1)));
  shift_part = shift_part & a;
  int ans = (x << n) | shift_part; 

  int shift_size = 32 + (~n+1);
  int a = ~((0x80 <<24) >> (shift_size + (~1+1)));
  int shift_part = (x & a) << shift_size;
  x = (x >> n) & ~((0x80 << 24) >> (n+(~1+1)));
  return x | shift_part; */

/*
  int sign_bit = (~n+1) >> 31; //0 for 0, -1 for rest
  int shift_size = (32 + (~n+1)) & sign_bit;
  int all_ones = ~0;
  int a = (all_ones >> n) << n;
  a = ~a;
  int shifted_part = (x & a) << shift_size;
  int clear_bits = ~((sign_bit >> shift_size) << shift_size);
  x = (x>>n) & (clear_bits);
  return x | shifted_part; */
