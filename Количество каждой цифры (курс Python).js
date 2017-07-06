"use strict"
var fs = require('fs');
var input = "input.txt";
var output = "output.txt";

var sinput = fs.readFileSync(input, "utf8");
var arrinput = sinput.split("\n");
var res = [0,0,0,0,0,0,0,0,0,0];
for (var x = 1; x <= arrinput[0]*1; x++){
	res[arrinput[x]*1]++;
}
var resstr = ""
for (var i = 1; i < res.length*1; i++){
	resstr += res[i] += ' ';
}
resstr += res[0];
fs.writeFileSync(output, resstr);
