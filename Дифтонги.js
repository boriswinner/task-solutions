"use strict"
var fs = require('fs');
var input = "input.txt";
var output = "output.txt";
var reg = /(^|[^aeiouy])[aeiouy][aeiouy]($|[^aeiouy])/g

var arr_input = fs.readFileSync(input, "utf8");
arr_input = arr_input.split(/\s+/g)

var n = +arr_input[0];
arr_input.shift();
var max = 0;
var l = Array(arr_input.length);
for (var x = 0; x < n; ++x){
	l[x] = 0;
	var match;
	while (match = reg.exec(arr_input[x])) { 
		l[x]++;
		reg.lastIndex = match.index+1;
	}
    if (l[x] > max) max = l[x];
}

var str_out = "";
for (var x = 0; x < n; ++x){
	if (l[x] === max) str_out += (arr_input[x] + '\n');
}
fs.writeFileSync(output, str_out);
