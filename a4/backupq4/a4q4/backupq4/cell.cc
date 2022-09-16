#include "cell.h"
#include "error.h"
Cell::Cell(size_t r, size_t c):r{r},c{c}{}

  void Cell::setPiece(Colour colour){
		this->colour=colour;
	}    // Place a piece of given colour here.
  void Cell::toggle(){
		State s=getState();
		colour=s.colour;	
	}         

Direction	getDirection(int r, int c, int oldr, int oldc){
		if(r==oldr){
			if(c==oldc+1){return Direction::E;}
			if(c==oldc-1){return Direction::W;}
		}else if(c==oldc){
			if(r==oldr+1){return Direction::S;}
			if(r==oldr-1){return Direction::N;}
		}else if((r==oldr+1) &&(c==oldc+1)){return Direction::NW;}
			else if((r==oldr+1) &&(c==oldc-1)){return Direction::NE;}
			else if((r==oldr-1) &&(c==oldc-1)){return Direction::SE;}
			else if((r==oldr-1) &&(c==oldc+1)){return Direction::SW;}
			throw(DirectionNF());
			return Direction::NE;
	}	


  void Cell::notify(Subject<Info, State> &whoFrom){
		State fromstate= whoFrom.getState();
		Info frominfo=whoFrom.getInfo();
		if (fromstate.type==StateType::NewPiece){
			Direction d=getDirection(r,c,frominfo.row, frominfo.col);
			if(fromstate.colour!=colour){
				State newState{StateType::Relay,frominfo.colour,d};
				setState(newState);
			}
			if(fromstate.colour==colour){return;}
		}
		else if (fromstate.type==StateType::Relay){
			Direction d=getDirection(r,c,frominfo.row, frominfo.col);
			if(d!=fromstate.direction){return;}
//d==fromstate.direction
			if(fromstate.colour==colour){setState(fromstate);}
			else{
				toggle();
				fromstate.type=StateType::Reply;
				setState(fromstate);
			}
			
		}
		else if (fromstate.type==StateType::Reply){		
			Direction d=getDirection(frominfo.row, frominfo.col,r,c);
		  if (d!=fromstate.direction){return;}
			else{
				toggle();
				setState(fromstate);
			}
		}
	notifyObservers();
	}
  Info Cell::getInfo() const{
		Info i{r,c,colour};
		return i;
	}

