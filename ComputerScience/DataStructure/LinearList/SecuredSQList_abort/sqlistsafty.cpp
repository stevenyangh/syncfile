 #include"sqlistconf.hpp"

//judge,all other functions used in judge part should include a"pure head" in case for dead loop.
bool jls(sqlist &l,bool reqexist,int loopnumber){
  int i; 
  if(loopnumber<=loopnumberlimit){
    if(reqexist){
      if(l.lenth>0){
	if(l.size<l.lenth){
	  pureincreaseto(l,l.lenth);
	  warn("list size increased");
	  return jls(l,reqexist,loopnumber++);
	}
	else{
	  return true;
	}
      }
      else{
	pureinitlist(l);
	warn("list does not exist,auto initiated and operated,recommanded to check if the list is correct.");
	return jls(l,reqexist,loopnumber++);
      }
    }
    else{
      if((l.lenth>0)||(l.size>0)){
	puredestroylist(l);
	warn("the list had been destroyed");
	jls(l,reqexist,loopnumber++);
      }
      else{
	return true;
      }
    }
  }
  else{
      warn("can't fix list");
      return false;
  }
}
//this function will fix bug in list and judge whether the list is suitable for operation,be careful,when you set the list "does not require to be exist",the function will delete it's data.
  
bool jle(sqlist &l,int i,bool reqexist,int loopnumber){
  if(loopnumber<=loopnumberlimit){
    if(jls(l,objexist,0)){
      if(i>0){
	if(i<=l.lenth){
	  return true;
	}
	else{
	  if(reqexist){
	    warn("the element doesn't exist, > lenth.");
	    return false;
	  }
	  else{
	    pureincreaseto(l,i);
	    earn("list has been expended.");
	    return jle(l,i,reqexist,loopnumber++);
	  }
	}
      }
      else{
	warn("the element doesn't exist, < 0.");
	return false;
      }
    }
    else{
      warn("the list doesn't exist.");
      return false;
    }
  }
  else{
    warn("can't fix list.");
    return false;
  }
}
//this function will test whether a element in the list exists,when required to exist,the function return false if the list or the element doesn't,when it's not strictly required,it will expand the list.the function will do no harm to data.

bool jps(sqlist &l,int lstart,int lend,bool reqexist){
  return jle(l,lend,reqexist,0);
}//this function is clear

bool jpd(sqlist &l,int lstart,int lend,sqlist &m,int mstart,int mend){
  return ((jps(l,lstart,lend,!objexist))&&(jps(m,mstart,mend,!objexist)));
}//this function is clear,too,actually,they do nothing else. 

//jaes
bool jaelists(fls f,sqlist &l,bool reqexist){
  if(jls(l,reqexist)){
    f(l);
    return true;
  }
  else{
    warn("operation wrong");
    return false;
  }
}

bool jaelistelem(fle f,sqlist &l,int i,bool reqwxist){
  if(jle(l,i)){
    f(l,i);
    return true;
  }
  else{
    warn("operation wrong");
    return false;
  }
}

bool jaepieces(fps f,sqlist &l,int lstart,int lend,bool reqexist){
  if(jps(l,lstart,lend,reqexist)){
    f(l,lstart,lend);
    return true;
  }
  else{
    warn("operation wrong");
    reutrn false;
  }
}

bool jaepieced(fpd f,sqlist &l,int lstart,int lend,sqlist &m,int mstart,int mend){
  if(jps(l,lstart,lend,m,mstart,mend)){
    f(l,lstart,lend,m,mstart,mend);
    retun true;
  }
  else{
    warn("operation wrong");
    return false;
  }
}
