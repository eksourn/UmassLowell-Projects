/* *
 * Ethan Sourn
 * 6/28/2022
 * GUI Programming 1
 * Homework 5: Implementing a Bit of Scrabble with Drag-and-Drop (with Extra Credits)
 * 
 *  Features: Currently incomplete, has not working code for generate sources and targets for drag and droppable
 * */

//  Draggable tiles from https://jqueryui.com/draggable/
//  Generates all the tiles for the scrabble board
function generateSources() {
    //  debugging
    alert("hello");
    
    var every_letter = [];  //  Holds every letter tile for use later (100)
    var letter;     //  Holds current letter
    var total = 0;  //  This should add up to 100 for all the tiles
    
    for (var i = 0; i < 26; i++) {
        var curr_ltr = pieces[i].letter;  //  Get letter from Ramon Meza's JSON structure
        var amount = pieces[i].amount;  //  Get remaining occurences of the current letter
        total += amount;
        for(var j = 0; j < amount; j++) {
            every_letter.push(curr_ltr);    //  Push x amount of said letter into array
        }
    }
    //  Pick random number 0 - 99
    var temp = total - 1;
    var rand = Math.floor(Math.random() * (temp - 0 + 1)) + 0;
    letter = every_letter[rand];  //  Letter should hold the calculated number
    //  Update total pieces
    for (var i = 0; i < 26; i++) {
        if (pieces[i].letter == letter) {
            pieces[i].remaining--;
        }
    }
    var scrab_tile;  //  Will hold img of tile
    var scrab_tile_ID;  //  Hold id of scrab title
    var rack_pos;  //  Hold rack position
    //  Now finally create 7 pieces to play for the current round
    for (j = 0; j < 7; j++) {
        scrab_tile = "<img class='pieces' id='piece" + i + "' src='" + "'letters/Scrabble_Tile_'" + letter + ".jpg" + "'></img>";
        scrab_tile_ID = "#piece" + i;
        rack_pos = $('#rack').position();
        //  Retrieve position
        pos_left = rack_pos.left + 30 + (25 * i);
        pos_top = rack_pos.top + 30;
        //  Append piece to screen
        $('#rack').append(scrab_tile);
        //  Move piece onto rack
        $(scrab_tile_ID).css("left", pos_left).css("top", pos_top).css("position", "absolute");
        //  Draggable
        $(scrab_tile_ID).draggable( {
            //  properties
        });
    }
}
//  Generates all the targets on the scrabble one line board
function generateTargets() {

}