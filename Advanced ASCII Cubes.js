"use strict"
var fs = require('fs');
var input = "input.txt";
var output = "output.txt";

var arr_input = fs.readFileSync(input, "utf8");
arr_input = arr_input.split(/\s+/g)

var n = arr_input[0];
var m = arr_input[1];
arr_input.shift();
arr_input.shift();
var max_h = Math.max.apply(null, arr_input);

var h = 1000;
var w = 1000;
console.log(max_h);

var arr = new Array(h);
for (var i = 0; i < h; i++) {
  arr[i] = new Array(w);
  for (var j = 0; j < w; j++){
	  arr[i][j] = '.';
  }
}
 
function putCube(i,j){
	arr[i][j] = '+';
	arr[i][j+1] = '-';
	arr[i][j+2] = '-';
	arr[i][j+3] = '-';
	arr[i][j+4] = '+';
	arr[i+1][j] = '|';
	arr[i+1][j+1] = ' ';
	arr[i+1][j+2] = ' ';
	arr[i+1][j+3] = ' ';
	arr[i+1][j+4] = '|';
	arr[i+1][j+5] = '/';
	arr[i+2][j] = '|';
	arr[i+2][j+1] = ' ';
	arr[i+2][j+2] = ' ';
	arr[i+2][j+3] = ' ';
	arr[i+2][j+4] = '|';	
	arr[i+2][j+5] = ' ';	
	arr[i+2][j+6] = '+';	
	arr[i+3][j] = '+';
	arr[i+3][j+1] = '-';
	arr[i+3][j+2] = '-';
	arr[i+3][j+3] = '-';
	arr[i+3][j+4] = '+';
	arr[i+3][j+5] = ' ';	
	arr[i+3][j+6] = '|';
	arr[i+4][j+1] = '/';
	arr[i+4][j+2] = ' ';
	arr[i+4][j+3] = ' ';
	arr[i+4][j+4] = ' ';
	arr[i+4][j+4] = ' ';
	arr[i+4][j+5] = '/';
	arr[i+4][j+6] = '|';
	arr[i+5][j+2] = '+';
	arr[i+5][j+3] = '-';
	arr[i+5][j+4] = '-';
	arr[i+5][j+5] = '-';
	arr[i+5][j+6] = '+';
}

var heights = new Array(n);
var cnt = 0;
for (var i = 0; i < n; i++) {
  heights[i] = new Array(m);
  for (var j = 0; j < m; j++){
	  heights[i][j] = arr_input[cnt];
	  cnt++;
  }
}

for (var q = 0; q < max_h; ++q){
	for (var y = n-1; y >= 0; --y){
		for (var i = 0; i < m; ++i){
			if (heights[n-1-y][i] >= q+1) putCube(2*y+3*q,2*y+4*i);
		}
	}
}

var res = "";
var maxl = 0;
for (var i = h-1; i >= 0; i--){
		var tstr = arr[i].join('');
		var p = tstr.lastIndexOf('+');
		var m = tstr.lastIndexOf('-');
		var s = tstr.lastIndexOf('/');
		var r = tstr.lastIndexOf('|');
		var l = Math.max(p,m,s,r);	
		if (l === -1) continue;
		if (l > maxl) maxl = l;
}
console.log(maxl);

for (var i = h-1; i >= 0; i--){
		var tstr = arr[i].join('');
		var p = tstr.lastIndexOf('+');
		var m = tstr.lastIndexOf('-');
		var s = tstr.lastIndexOf('/');
		var r = tstr.lastIndexOf('|');
		var l = Math.max(p,m,s,r);	
		if (l === -1) continue;		
		var tstr2 = tstr.slice(0,maxl+1);
		res += tstr2;
		if (tstr2.length > 0) res += '\n';
}
fs.writeFileSync(output, res);
