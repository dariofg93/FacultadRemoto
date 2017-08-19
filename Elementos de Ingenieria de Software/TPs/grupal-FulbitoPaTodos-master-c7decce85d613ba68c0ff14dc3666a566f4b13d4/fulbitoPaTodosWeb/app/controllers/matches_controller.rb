class MatchesController < ApplicationController
    def index
        @matches = Match.all

    end

    def new
        @match = Match.new
    end

    def create
        @match = Match.create!(new_match_params)
        MatchesUser.create_with_ids(@match.id, current_user.id)
        flash[:notice] = "Nuevo Partido Creado!"
        redirect_to "/matches"
    end

    def show
        @match = Match.find(params[:id])
    end

    def update
          if  MatchesUser.exists?(["user_id = ? AND match_id = ?", current_user.id, params[:id]])
            flash[:notice] = "Ya te uniste a este partido!"
            redirect_to "/matches"
          else
            #MatchesUser.create_with_ids(params[:id], current_user.id)
            #flash[:notice] = "Te Uniste Al Partido!"
            flash[:notice] = MatchesUser.create_if_not_exclusive(params[:id], current_user.id)
            redirect_to "/matches"
          end
    end

    def search
    end

    def searchResult
        #p = search_params
        @matches = Match.where(["place = ?", params[:place]])
        if @matches == []
            flash[:notice] = "No se encontraron partidos con esas caracteristicas" + String(params[:place]) + "asd"
        end
    end

    private

    def search_params
        params.require(:match).permit(:place, :date, :time)
    end

    def new_user_params
        params.require(:match).permit(:users, :email)
    end

    def new_match_params
        params.require(:match).permit(:place, :date, :time)
    end
end
