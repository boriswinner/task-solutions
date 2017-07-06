"use strict"
var fs = require('fs');
var input = "input.txt";
var output = "output.txt";
 
String.prototype.repeat = function(n){
    n= n || 1;
    return Array(n+1).join(this);
}
 
 
var sinput = fs.readFileSync(input, "utf8");
var sinput_splitted = sinput.split(/\s+/g);
 
var n = sinput_splitted[0]*1;
var a = new Array(n);
for (var i = 1; i <= n; ++i){
    a[i-1] = sinput_splitted[i];
}
 
console.log(a);
 
var width = 5*n + (2 + (n-1)); 
var height = 2 + 1 + Math.max.apply(null, a)*1;
 
var res = ""
res += '.'.repeat(width);
res += '\n';
for (var i = height-1; i > 0; i--){
    var s = "";
    if (i === 1){
        s += "-";
    } else{
        s += ".";
    }
    for (var j = 0; j < n; j++){
        if (i > a[j]*1+2){
            s += ".....";
        } else if (i === a[j]*1+2){
            s += "+---+";
        } else if (i === 1){
            s+= "+---+";
        } else if (i <= a[j]*1+1){
            s += "|###|";
        }
        if (i === 1){
            s+="-";
        } else {
            s+= ".";  
        }
    }
    s += "\n";
    res += s;
}
fs.writeFileSync(output, res);
console.log(width);
console.log(height);
