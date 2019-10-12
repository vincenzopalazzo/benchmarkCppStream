
"use strict";

class DAOLocalFile{

    constructor(path){
        this.path = path;
    }

    loadFile(path){
        this.configurationData;
        return fetch(path)
                .then(response => response.json())
                    .then(function(data){
                        console.debug("Response to path: " + path);
                        console.debug(data);
                        return data;
                    })
                    .catch(ex => console.error(ex));
    }
}