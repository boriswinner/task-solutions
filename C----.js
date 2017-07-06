"use strict"
var fs = require('fs');
var input = "input.txt";
var output = "output.txt";

var ain = fs.readFileSync(input, "utf8");
ain = ain.split(/\s+\n/g)

var stack = [];
var stack_val = [];
var resstr = "";

function writeElem(index, elem){
	if (stack.lastIndexOf(elem) != -1){
		writeElem(index, stack_val[stack.lastIndexOf(elem)]);
	} else {
		stack_val[index] = elem;
	}
}

for (var i in ain){
	if (ain[i] == '{'){
		stack.push('{');
		stack_val.push('{');
	} else if (ain[i] == '}'){
		var p;
		while ((p = stack.pop()) != '{'){stack_val.pop();}
	} else if (ain[i].substr(0,3) === "int"){
		var val = ain[i].split(" ");
		stack.push(val[1]);
		stack_val.push(0);
	} else if(ain[i].substr(0,5) == 'print'){
		var val = ain[i].split(" ");
		resstr += (stack_val[stack.lastIndexOf(val[1])]+'\n');
	} else if (ain[i].split("=").length === 2){
		var val = ain[i].split("=");
		var p;
		p = stack.lastIndexOf(val[0]);
		writeElem(p,val[1]);
	}
	fs.writeFileSync(output, resstr);
}
