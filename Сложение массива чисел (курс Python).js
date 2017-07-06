"use strict"
var fs = require('fs');
var input = "input.txt";
var output = "output.txt";

var sinput = fs.readFileSync(input, "utf8");
var sinput_splitted = sinput.split(/\s+/g);
var res = 0;
for (var i = 1; i <= sinput_splitted[0]; ++i){
	res += sinput_splitted[i]*1;
}
fs.writeFileSync(output, res);
