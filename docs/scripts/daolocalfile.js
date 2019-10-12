"use strict";

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

var DAOLocalFile =
/*#__PURE__*/
function () {
  function DAOLocalFile(path) {
    _classCallCheck(this, DAOLocalFile);

    this.path = path;
  }

  _createClass(DAOLocalFile, [{
    key: "loadFile",
    value: function loadFile(path) {
      this.configurationData;
      return fetch(path).then(function (response) {
        return response.json();
      }).then(function (data) {
        console.debug("Response to path: " + path);
        console.debug(data);
        return data;
      }).catch(function (ex) {
        return console.error(ex);
      });
    }
  }]);

  return DAOLocalFile;
}();
//# sourceMappingURL=daolocalfile.js.map
