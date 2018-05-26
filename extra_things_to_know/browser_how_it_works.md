### Browser components

             -----------------------------
            |     User Interface          |
             -----------------------------
                    |                   |          -------------
                    v                   |         |             |
             ----------------           |         |             |
            | Browser Engine | -----------------> | Data        |
             ----------------           |         | Persistence |
                    |                   |         |             |
                    v                   |          -------------
         ---------------------------    |
        |     Rendering Engine      |   |
         ---------------------------    |
            |         |           |     |
            V         V           V     V
   ------------   -------------   ------------
  | Networking | | Javascript  | | UI Backend | 
   ------------  | Interpreter |  ------------
                  -------------

#### User Interface:
 - Everything that you can see but cannot manipulate
 - E.g. address bar, settings
 - works together with UI Backend

#### UI Backend:
 - Designed to develop basic widgets

#### Browser Engine:
 - Works as a mediator between user interface and rendering engine
 - E.g. On pressing refresh, the browser engine takes the command and carries it out

#### Rendering Engine:
 - Parses the html, css, and javascript; and displays it on the page

#### Networking:
 - Takes connections on http and https

#### Javascript Interpreter:
 - interprets the javascript

#### Data Persistence:
 - cookies, local storage, index DB, filesystem

### Rendering Engine flow:

     ---------------
    |    Parsing    |
     ---------------
            |
            v
     ---------------
    |  Render Tree  |
     ---------------
            |
            v
     --------------
    |    Layout    |
    |      or      |
    |    reflow    |
     --------------
            |
            v
     --------------
    |    Paint     |
     --------------

#### Parser: 2 types
 - Conventional Parser
   - CSS and Javascript
 - Unconventional Parser
   - HTML

#### Parsing consists of granner which entails:
 - vocabulary
 - syntax rules


