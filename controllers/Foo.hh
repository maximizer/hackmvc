<?hh
/**
 * Hack MVC
 *
 * @author Patrick Mizer
 */
class Foo extends Controller
{
    public function indexAction() : void {
        $data = new Map<string, mixed>();
        $data["foo"] = $this->GETParams()->get("foo");

        $this->renderView('index/index.tpl.hh', $data);        
    }
    
}