function myFunction() {

//Open the event Calender  
  var spreadsheet = SpreadsheetApp.getActiveSheet();
  var calendarId = spreadsheet.getRange("D2").getValue();
  var eventCal = CalendarApp.getCalendarById(calendarId);
  
//Pulling each infromation
  var signups = spreadsheet.getRange("A8:DA7").getValues();  
  
//Copying and pasting the schedule to calender 
  for (x=0; x<signups.length; x++) {
    
    var shift = signups[x];
    
    var deadline = shift[0];
    var task = shift[1]
    eventCal.createEvent(task, deadline);
    
  }
  
}

function onOpen(){
  var ui = SpredsheetApp.getUi();
  ui.createMenu('Sync to Calendar')
     .addItem('Schedule now')
     .addToUi();
}
  
