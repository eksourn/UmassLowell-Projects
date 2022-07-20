/**
 * Ethan Sourn
 * 6/21/2022
 * GUI Programming 1
 * Homework 4: Using the jQuery Plugin/UI with Your Dynamic Tabl
 * 
 * mult-table.js holds all js functions used to generate the multiplcation table
 * WIP: (1) Using slider and then submitting the form works as intented when displaying tabs but not for entering values normally,
 *      (2) Two way binding for slider and submission field
 *      (3) Delete multiple tabs
 */
/**
 * calculateTable Function
 * Takes no parameters but is called with onclick in html
 * It retrieves input from form, turns it into number via typecast,
 * and is validated. It also calculates all the values and is saved
 * to an array. Then finally creates all the cells and populates it
 * and loads to page
 * 
 * slider Function
 * Takes no parameter and is called during ready function
 * It grabs all sliders, assign initial attributes such as range and step
 * and submits new values into the form based on the slider events 'slide' and
 * 'change'.
 * 
 * saveCurrTab Function
 * Takes no parameters and is called by onclick event on the submit button.
 * It grabs table dimensions and generates a tab and displays the content from
 * calculateTable function. The delete functionalities are currently not working.
 */
 var tabIndex = 1;
//  Updates and regenerates the table column/row values based on sliders
function slider() {
    $("#mincSlider").slider({
        //  Slider attributes for range, step count, smoothness, and starting value
        min: -100,
        max: 100,
        animate: true,
        value: 0,
        //  Based off https://jesseheines.com/~heines/91.461/91.461-2015-16f/461-assn/jQueryUI1.8_Ch06_SliderWidget.pdf and
        //  On events slide and change retrieve value from corresponding input id and pass into func
        slide: function(e, ui) {
            updateInpFromSlider("#minCol", $(this).slider("value"));
        },
        change: function(e, ui) {
            updateInpFromSlider("#minCol", $(this).slider("value"));
        }
    });
    $("#maxcSlider").slider({
        min: -100,
        max: 100,
        animate: true,
        value: 0,
        slide: function(e, ui) {
            updateInpFromSlider("#maxCol", $(this).slider("value"));
        },
        change: function(e, ui) {
            updateInpFromSlider("#maxCol", $(this).slider("value"));
        }
    });
    $("#minrSlider").slider({
        min: -100,
        max: 100,
        animate: true,
        value: 0,
        slide: function(e, ui) {
            updateInpFromSlider("#minRow", $(this).slider("value"));
        },
        change: function(e, ui) {
            updateInpFromSlider("#minRow", $(this).slider("value"));
        }
    });
    $("#maxrSlider").slider({
        min: -100,
        max: 100,
        animate: true,
        value: 0,
        slide: function(e, ui) {
            updateInpFromSlider("#maxRow", $(this).slider("value"));
        },
        change: function(e, ui) {
            updateInpFromSlider("#maxRow", $(this).slider("value"));
        }
    });
    //  Manual input updates slider value ref from https://write.corbpie.com/updating-an-input-value-from-a-jquery-slider/
    $("#minCol").change(function() {
        $("#mincSlider").slider("value", $(this).val());
        $("#mincSlider").prop("value", $(this).val());
    });
    $("#maxCol").change(function() {
        $("#maxcSlider").slider("value", $(this).val());
        $("#maxcSlider").prop("value", $(this).val());
    });
    $("#minRow").change(function() {
        $("#minrSlider").slider("value", $(this).val());
        $("#minrSlider").prop("value", $(this).val());
    });
    $("#maxRow").change(function() {
        $("#maxrSlider").slider("value", $(this).val());
        $("#maxrSlider").prop("value", $(this).val());
    });
}
//  Simply retrieves the slider_id value and submit into form
function updateInpFromSlider(slider_id, value) {
    $(slider_id).val(value);
    $(slider_id).submit();
}
//  Save current multiplaction table into a tab
function saveCurrTab() {
    tabIndex++; 
    //  Get current inputs from the form
    var minCol = Number(document.getElementById('minCol').value);
    var maxCol = Number(document.getElementById('maxCol').value);
    var minRow = Number(document.getElementById('minRow').value);
    var maxRow = Number(document.getElementById('maxRow').value);
    //  Title of the tab is the dimensions of the table and delete button
    var title = "<li class='tab'><a href='#tab" + tabIndex + "'>" + minRow + " to " + maxRow + " by " + minCol + " to " + maxCol + "</a>" + 
        "<button type='button' class='delete'>X</button></li>";
    //  Append to tabs ul
    $("div#tabs ul").append(title);
    //  Add current mult table
    $("div#tabs").append('<div id="tab' + tabIndex + '">' + $("#mult_table").html() + '</div>')
    //  Refresh tabs so content looks fine
    $("#tabs").tabs("refresh");
    //  Automatically display generated tab w/ active option
    $("#tabs").tabs("option", "active", -1);
    //  Delete individual tabs from https://stackoverflow.com/questions/3521275/removing-a-jquery-ui-tab
    /* WIP*******
    $(".delete").click(function() {
        //  Have to select a tab first then click the X button for it to work
        var selIndex = $("#tabs").tabs("option", "active");
        //  Debugging
        //alert(selIndex);
        $("#tabs").tabs("remove", selIndex);
        $("#tabs").tabs("refresh");
    });*/
}
function calculateTable() {
    //  Retrieve input
    var minCol = Number(document.getElementById('minCol').value);
    var maxCol = Number(document.getElementById('maxCol').value);
    var minRow = Number(document.getElementById('minRow').value);
    var maxRow = Number(document.getElementById('maxRow').value);/*
    // Begin error checking input
    // Empty form field
    if (minCol == '' || maxCol == '' || minRow == '' || maxRow == '') {
        return false;
    }
    //  Range requirements for all input fields
    if (minCol <= 1000 && minCol >= -1000) {
        return false;
    }
    if (maxCol <= 1000 && maxCol >= -1000) {
        return false;
    }
    if (minRow <= 1000 && minRow >= -1000) {
        return false;
    }
    if (maxRow <= 1000 && maxRow >= -1000) {
        return false;
    }*/
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

