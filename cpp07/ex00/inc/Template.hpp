/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#pragma once

template <typename T>
void swap(T& a, T& b){
	T c = b;
	b = a;
	a = c;
}

template <typename T>
const T& min(const T& a, const T& b) {
	if (a > b)
		return (b);
	else
		return (a);
}

template <typename T>
const T& max(const T& a, const T& b) {
	if (a > b)
		return (a);
	else
		return (b);
}
