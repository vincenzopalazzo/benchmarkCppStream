"use strict";

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

var RES_PATH = "res/";
var colors = {
  backgroundColor: ['rgba(255, 99, 132, 0.2)', 'rgba(54, 162, 235, 0.2)', 'rgba(255, 206, 86, 0.2)', 'rgba(75, 192, 192, 0.2)', 'rgba(153, 102, 255, 0.2)', 'rgba(255, 159, 64, 0.2)'],
  borderColor: ['rgba(255, 99, 132, 1)', 'rgba(54, 162, 235, 1)', 'rgba(255, 206, 86, 1)', 'rgba(75, 192, 192, 1)', 'rgba(153, 102, 255, 1)', 'rgba(255, 159, 64, 1)']
};
var loadNum = -1;

var BuilderChart =
/*#__PURE__*/
function () {
  function BuilderChart(idCanvas, typeChart, labels) {
    _classCallCheck(this, BuilderChart);

    this.idCanvas = idCanvas;
    this.typeChart = typeChart;
    this.labels = labels;
    this.chart = new Chart(this.idCanvas, {
      type: this.typeChart,
      data: {
        labels: this.labels
      },
      borderWidth: 2,
      options: {
        scales: {
          yAxes: [{
            ticks: {
              beginAtZero: true
            }
          }]
        }
      }
    });
  }

  _createClass(BuilderChart, [{
    key: "loadConfigurator",
    value: function loadConfigurator() {
      var self = this;
      var path = RES_PATH + "demo-conf.json";
      var dao = new DAOLocalFile(path);
      var configData = dao.loadFile(path);
      configData.then(function (config) {
        var files = config.results;
        console.debug('files: ' + files);
        files.forEach(function (file) {
          var promisseFile = dao.loadFile(RES_PATH + file);
          promisseFile.then(function (dataFile) {
            console.debug("The object file is: " + dataFile);
            loadNum++;
            self.updateBarGraph(file.replace('.json', ''), colors.backgroundColor[loadNum], colors.borderColor[loadNum], [dataFile.benchmarks[0]['real_time'] / 1000000000.0, dataFile.benchmarks[1]['real_time'] / 1000000000.0, dataFile.benchmarks[2]['real_time'] / 1000000000.0, dataFile.benchmarks[3]['real_time'] / 1000000000.0, dataFile.benchmarks[4]['real_time'] / 1000000000.0, dataFile.benchmarks[5]['real_time'] / 1000000000.0, dataFile.benchmarks[6]['real_time'] / 1000000000.0]);
          });
        });
      });
    }
  }, {
    key: "buildChart",
    value: function buildChart() {
      this.loadConfigurator();
    }
  }, {
    key: "updateBarGraph",
    value: function updateBarGraph(label, color, borderColor, data) {
      this.chart.data.datasets.push({
        label: label,
        backgroundColor: color,
        borderColor: borderColor,
        data: data
      });
      this.chart.update();
    }
  }]);

  return BuilderChart;
}();
//# sourceMappingURL=builder-chart.js.map
