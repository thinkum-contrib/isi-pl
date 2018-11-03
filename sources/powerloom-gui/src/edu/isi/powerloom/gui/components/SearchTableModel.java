// -*- Mode: Java -*-

/*---------------------------- BEGIN LICENSE BLOCK ---------------------------+
 |                                                                            |
 | Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
 |                                                                            |
 | The contents of this file are subject to the Mozilla Public License        |
 | Version 1.1 (the "License"); you may not use this file except in           |
 | compliance with the License. You may obtain a copy of the License at       |
 | http://www.mozilla.org/MPL/                                                |
 |                                                                            |
 | Software distributed under the License is distributed on an "AS IS" basis, |
 | WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
 | for the specific language governing rights and limitations under the       |
 | License.                                                                   |
 |                                                                            |
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 2002-2010      |
 | the Initial Developer. All Rights Reserved.                                |
 |                                                                            |
 | Contributor(s):                                                            |
 |                                                                            |
 | Alternatively, the contents of this file may be used under the terms of    |
 | either the GNU General Public License Version 2 or later (the "GPL"), or   |
 | the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
 | in which case the provisions of the GPL or the LGPL are applicable instead |
 | of those above. If you wish to allow use of your version of this file only |
 | under the terms of either the GPL or the LGPL, and not to allow others to  |
 | use your version of this file under the terms of the MPL, indicate your    |
 | decision by deleting the provisions above and replace them with the notice |
 | and other provisions required by the GPL or the LGPL. If you do not delete |
 | the provisions above, a recipient may use your version of this file under  |
 | the terms of any one of the MPL, the GPL or the LGPL.                      |
 |                                                                            |
 +----------------------------- END LICENSE BLOCK ---------------------------*/


// Version: SearchTableModel.java,v 1.5 2010/02/04 05:19:36 hans Exp

package edu.isi.powerloom.gui.components;

import java.util.*;
import javax.swing.table.*;
import edu.isi.powerloom.gui.xmlobject.*;
import static edu.isi.powerloom.gui.common.Utils.*;


/**
 * Table model for holding search results.
 *
 * @author <a href=mailto:eric@metrotech-consulting.com>Eric Melz</a>
 * @since Thu May 23 12:31:31 2002
 */

public class SearchTableModel extends AbstractTableModel {
    PLSearchResult searchResult;
    String columnNames[] =  {"Object", "Module", "Type"};
    List sortedItems;
    Comparator objectComparator, moduleComparator, typeComparator;


    public SearchTableModel() {
    }
    public SearchTableModel(PLSearchResult searchResult) {
	this.searchResult = searchResult;
	sortedItems = (List)searchResult.elemPLSearchResultItem;
	objectComparator = new Comparator() {
		public int compare(Object x, Object y) {
		    PLSearchResultItem obj1 = (PLSearchResultItem)x;
		    PLSearchResultItem obj2 = (PLSearchResultItem)y;
		    return obj1.elemPLObjectUnion.elemPLSurrogate.getID().compareTo(obj2.elemPLObjectUnion.elemPLSurrogate.getID());
		}
	    };
	moduleComparator = new Comparator() {
		public int compare(Object x, Object y) {
		    PLSearchResultItem obj1 = (PLSearchResultItem)x;
		    PLSearchResultItem obj2 = (PLSearchResultItem)y;
		    return obj1.attrModuleName.compareTo(obj2.attrModuleName);
		}
	    };
	typeComparator = new Comparator() {
		public int compare(Object x, Object y) {
		    PLSearchResultItem obj1 = (PLSearchResultItem)x;
		    PLSearchResultItem obj2 = (PLSearchResultItem)y;
		    return obj1.elemPLObjectUnion.attrType.compareTo(obj2.elemPLObjectUnion.attrType);
		}
	    };
	sortColumn(0);
    }
    public int getColumnCount() {
	return columnNames.length;
    }

    public void sortColumn(int columnIndex) {
	switch (columnIndex) {
	case 0:
	    Collections.sort(sortedItems, objectComparator);	    
	    break;
	case 1:
	    Collections.sort(sortedItems, moduleComparator);	    
	    break;
	case 2:
	    Collections.sort(sortedItems, typeComparator);	    
	    break;
	}
    }
    public String getColumnName(int i) {
	if ((columnNames != null) && (i >= 0) && (i < columnNames.length)) {
	    return columnNames[i];
	}
	return "UNKNOWN" + i;
    }
    public int getRowCount() {
	if ((searchResult == null) || (searchResult.elemPLSearchResultItem == null)) {
	    return 0;
	}
	return searchResult.elemPLSearchResultItem.size();
    }
    public Object getValueAt(int row, int column) {
	if ((column < 0) || (column > getColumnCount())) {
	    debugPrintln(3, "***warning columnCount of " + column + " is not in range.");
	    return null;
	}
	if ((searchResult == null) || (searchResult.elemPLSearchResultItem == null)) {
	    return null;
	}
	PLSearchResultItem searchItem = (PLSearchResultItem)sortedItems.get(row);
	if (column == 0) {  // module
	    PLObjectUnion plObjectUnion = searchItem.elemPLObjectUnion;
	    return plObjectUnion.getObject();
	} else if (column == 1) {  // type
	    return searchItem.attrModuleName;
	} else if (column == 2) {  // object
	    PLObjectUnion plObjectUnion = searchItem.elemPLObjectUnion;
	    return plObjectUnion.attrType;
	}
	/*
	    2 -> 0
		1 -> 2
                0 -> 1
	    */
	return null;
    }
    public void setSearchResult(PLSearchResult result) {
	this.searchResult = result;
    }
}
