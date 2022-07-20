/**
 * Ethan Sourn
 * 6/16/2022
 * GUI Programming 1
 * Homework 3: Creating an Interactive Dynamic Table
 * 
 * mult-table.js holds all js functions used to generate the multiplcation table
 */

/**
 * calculateTable Function
 * Takes no parameters but is called with onclick in html
 * It retrieves input from form, turns it into number via typecast,
 * and is validated. It also calculates all the values and is saved
 * to an array. Then finally creates all the cells and populates it
 * and loads to page
 */

function calculateTable() {
    //  Retrieve input
    var minCol = Number(document.getElementById('min-col').value);
    var maxCol = Number(document.getElementById('max-col').value);
    var minRow = Number(document.getElementById('min-row').value);
    var maxRow = Number(document.getElementById('max-row').value);
    // Begin error checking input
    // Empty form field
    if (minCol == '' || maxCol == '' || minRow == '' || maxRow == '') {
        document.getElementById('err-empty').innerHTML="Error: Empty input!";
        return false;
     }
    //  If mininum number is larger than maximum for row
    if (minRow > maxRow) {
        var temp = minRow;
        minRow = maxRow;
        maxRow = temp;
    }
    //  If mininum number is larger than maximum for col
    if (minCol > maxCol) {
        var temp = minCol;
        minCol = maxCol;
        maxCol = temp;
    }
    //  Get total amount of rows and columns and using abs for negative values
    var row = Math.abs(maxRow - minRow);
    var col = Math.abs(maxCol - minCol);
    /**
     * With nested loops I would calculate a single row of values for each 
     * column. When a row is completed I save it to an initally empty 
     * array which would be used to display it later. */
    var rIndex = minRow;
    var cIndex = minCol;
    var arr = [];
    for(var i = 0; i <= col; i++) {
        var temp_arr = [];
        for(var j = 0; j <= row; j++) {
            var result = rIndex * cIndex;
            temp_arr[j] = result;
            rIndex++;
        }
        arr["row" + i] = temp_arr;
        rIndex = minRow;
        cIndex++;
    }
    /**
    * Below is the code for filling the actual table
    */
    var tmpCol = minCol;
    //  This variable will hold table content
    var table = "";
    //  Opening table tag
    table += "<table>";
    //  Opening tr tag and top left corner with X
    table += "<tr><td>X</td>";
    //  First row
    for(var i = minRow; i <= row; i++) {
        table += "<td>" + i + "</td>";
    }
    table += "</tr>";
    //  Filling out rest of rows
    for(var j = 0; j <= col; j++) {
        //  Leftmost column
        table += "<tr><td>" + tmpCol + "</td>";
        //  Filling out actual table w/ the math
        for(var k = 0; k <= row; k++) {
            table += "<td>" + arr["row" + j][k] + "</td>";
        }
        tmpCol++;
        table += "</tr>";
    }
    //  Close table tag
    table += "</table>";
    //  Load into page
    document.getElementById("mult_table").innerHTML= table;
    return false;
}