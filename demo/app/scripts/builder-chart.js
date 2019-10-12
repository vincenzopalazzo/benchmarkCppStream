
'use strict';

var RES_PATH = 'res/';

let colors = {
    backgroundColor: [
      'rgba(255, 99, 132, 0.2)',
      'rgba(54, 162, 235, 0.2)',
      'rgba(255, 206, 86, 0.2)',
      'rgba(75, 192, 192, 0.2)',
      'rgba(153, 102, 255, 0.2)',
      'rgba(255, 159, 64, 0.2)'
    ],
    borderColor: [
      'rgba(255, 99, 132, 1)',
      'rgba(54, 162, 235, 1)',
      'rgba(255, 206, 86, 1)',
      'rgba(75, 192, 192, 1)',
      'rgba(153, 102, 255, 1)',
      'rgba(255, 159, 64, 1)'
    ]
  };

let loadNum = -1;

class BuilderChart{

    constructor(idCanvas, typeChart, labels){
        this.idCanvas = idCanvas;
        this.typeChart = typeChart;
        this.labels = labels;

        this.chart = new Chart(this.idCanvas, {
            type: this.typeChart,
            data: {
              labels: this.labels,
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

    loadConfigurator(){
        let self = this;
        let path = RES_PATH +  'demo-conf.json';
        let dao = new DAOLocalFile(path);
        let configData = dao.loadFile(path);
        configData.then(config => {
            let files = config.results;
            console.debug('files: ' + files) 
            files.forEach(function(file) {
                let promisseFile = dao.loadFile(RES_PATH + file);
                promisseFile.then(dataFile => {
                    console.debug('The object file is: ' + dataFile);
                    loadNum++;
                    self.updateBarGraph(file.replace('.json', ''), colors.backgroundColor[loadNum], colors.borderColor[loadNum],
                    [
                        dataFile.benchmarks[0]['real_time'] / 1000000000.0,
                        dataFile.benchmarks[1]['real_time'] / 1000000000.0,
                        dataFile.benchmarks[2]['real_time'] / 1000000000.0,
                        dataFile.benchmarks[3]['real_time'] / 1000000000.0,
                        dataFile.benchmarks[4]['real_time'] / 1000000000.0,
                        dataFile.benchmarks[5]['real_time'] / 1000000000.0,
                        dataFile.benchmarks[6]['real_time'] / 1000000000.0,
                        
                    ]
                    );
                })
            });
           

        });
    }

    buildChart(){
        this.loadConfigurator();
    }

    updateBarGraph(label, color, borderColor, data) {
        this.chart.data.datasets.push({
          label: label,
          backgroundColor: color,
          borderColor: borderColor,
          data: data
        });
        this.chart.update();
      }

}